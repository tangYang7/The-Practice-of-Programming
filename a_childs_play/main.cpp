#include <iostream>
#include <string>
#include "robot.h"
#include "maze.h"

using namespace std;
void checkObj(string &s, int row, Robot &bot, Maze &map);
int main()
{
    int w, h;
    Maze mymap;
    Robot mybot;
    cin >> w >> h; cin.ignore();
    mymap.InitMaze(w, h);

    long long n;
    cin >> n; cin.ignore();
    for(int i = 0; i < h; i++) 
    {
        string line;
        getline(cin, line);
        checkObj(line, i, mybot, mymap);
    }

    int pre_x = mybot.Robot_width();
    int pre_y = mybot.Robot_height();
    int count = 0;
    for(int i = 0; i < n; i++) 
    {
        while((mybot.IsFacingWall(mymap)))
        {
            mybot.TurnRight();
        }
        mybot.GoForward();

        int x = mybot.Robot_width();
        int y = mybot.Robot_height();
        int check_next = mybot.VisitNumber(x + mybot.Robot_forwardX(), y + mybot.Robot_forwardY());
        if(mybot.VisitNumber(pre_x, pre_y) >= 3)
        {
            if(mybot.VisitNumber(x, y) <= 2 && check_next < 2)      //It's extra to be saved in Loop_nAndLoc.
            {
                mybot.SetLoop_nAndLoc(pre_x, pre_y);
            }
            else        // It's ready to get the final location.
            {
                int tmp = (n - i) % mybot.Robot_loopAccount();
                mybot.SetRobotLocation(mybot.Robot_finalX(tmp), mybot.Robot_finalY(tmp));
                break;
            }
        }else if(mybot.VisitNumber(pre_x, pre_y) == 2)
        {
            if(mybot.VisitNumber(x, y) <= 1 && check_next < 1)  // repeated point (it's not we need)
            {
                pre_x = x, pre_y = y;
                continue;
            }
            else {  // saved in Loop_nAndLoc
                mybot.SetLoop_nAndLoc(pre_x, pre_y);
            }
        }
        pre_x = x, pre_y = y;
    }

    cout << mybot.Robot_width() << " " << mybot.Robot_height() << endl;
}

void checkObj(string &s, int row, Robot &bot, Maze &map)
{
    int len = s.length();
    for(int i = 0; i<len; i++)
    {
        if(s[i] == '#')
        {
            map.SaveWall(i, row);
        }
        else if(s[i] == 'O')
        {
            bot.SetRobotLocation(i, row);
        }
    }
}
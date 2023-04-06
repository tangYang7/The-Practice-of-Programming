#include <iostream>
#include <string>
#include "robot.h"
#include "maze.h"

using namespace std;
enum  {ONCE = 1, TWICE = 2, THREE_TIMES = 3};
void loadInfo(string &s, const int row, Robot &bot, Maze &map);
int main()
{
    int w, h;
    Maze mymap;
    Robot mybot;
    cin >> w >> h; cin.ignore();
    mymap.InitMaze(w, h);

    long long n;
    cin >> n; cin.ignore();
    for(int i = 0; i < h; ++i) 
    {
        string line;
        getline(cin, line);
        loadInfo(line, i, mybot, mymap);
    }

    int pre_x = mybot.Robot_x();
    int pre_y = mybot.Robot_y();
    int count = 0;
    for(int i = 0; i < n; ++i) 
    {
        while(mybot.IsFacingWall(mymap))
        {
            mybot.TurnRight();
        }
        mybot.GoForward();

        int x = mybot.Robot_x();
        int y = mybot.Robot_y();
        int check_next = mybot.VisitNumber(x + mybot.Robot_forwardX(), y + mybot.Robot_forwardY());
        if(mybot.VisitNumber(pre_x, pre_y) >= THREE_TIMES)
        {
            if(mybot.VisitNumber(x, y) <= TWICE && check_next < TWICE)      //It's extra to be saved in Loop_nAndLoc.
            {
                mybot.SetLoop_nAndLoc(pre_x, pre_y);
            }
            else        // It's ready to get the final location.
            {
                int tmp = (n - i) % mybot.Robot_loopAccount();
                mybot.SetRobotLocation(mybot.Robot_finalX(tmp), mybot.Robot_finalY(tmp));
                break;
            }
        } else if(mybot.VisitNumber(pre_x, pre_y) == TWICE)
        {
            if(mybot.VisitNumber(x, y) <= ONCE && check_next < ONCE)  // repeated point (it's not we need)
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

    cout << mybot.Robot_x() << " " << mybot.Robot_y() << endl;
}

void loadInfo(string &s, const int row, Robot &bot, Maze &map)
{
    for(int i = 0; i<s.length(); ++i)
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
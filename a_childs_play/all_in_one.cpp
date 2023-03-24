#include <iostream>
#include <string>
using namespace std;
#define MAX_WIDTH 22
#define MAX_HEIGHT 12

class Maze {
public:
    void InitMaze(const int w, const int h);
    void SaveWall(const int w, const int h);
    void SaveSpace(const int w, const int h);
    bool IsWall(const int w, const int h) const;
    void PrintMap() const {
        for(int j = 0; j < this->_height; j++){
            for( int i = 0; i < this->_width; i++){
                cout << this->_map[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    };
private:
    int _width = 0;
    int _height = 0;
    int _map[MAX_WIDTH][MAX_HEIGHT] = {0};
};

void Maze::InitMaze(const int w, const int h){
    _width = w;  
    _height = h;
}
void Maze::SaveWall(const int w, const int h){
    _map[w][h] = 1;
}
void Maze::SaveSpace(const int w, const int h){
    _map[w][h] = 2;
}
bool Maze::IsWall(const int w, const int h) const {
    if(this->_map[w][h] != 1)
        return false;
    return true;
}

class Robot
{
public:
    void SetNumOperation(const int n) {totalStep = n;};
    void SetRobotLocation(const int w, const int h);
    int Robot_width()   const { return this->_x; };
    int Robot_height()  const { return this->_y; };
    int Robot_forwardX()   const { return this->forwardX; };
    int Robot_forwardY()  const { return this->forwardY; };
    long long Robot_totalOp() const { return this->totalStep; };

    void GoForward(const Maze &mz);
    bool IsFacingWall(const Maze &mz) const;
    void TurnRight();
    int VisitNumber(const int x, const int y) const;
    void SetLoop_nAndLoc(const int x, const int y);
    int Robot_loopAccount()         const { return this->loop_n; };
    int Robot_finalX(const int n)   const { return this->loopLoc[n][0]; };
    int Robot_finalY(const int n)   const { return this->loopLoc[n][1]; };
private:
    int _x = 0;
    int _y = 0;
    long long totalStep = 1;
    int forwardX = 0;       // initially moves upwards
    int forwardY = -1;      // initially moves upwards
    int myvisit[MAX_WIDTH][MAX_HEIGHT] = {0};
    int loop_n = 0;
    int loopLoc[MAX_WIDTH * MAX_HEIGHT][2] = {0};
};


void Robot::SetRobotLocation(const int w, const int h){
    this->_x = w;
    this->_y = h;
}

void Robot::GoForward(const Maze &mz){
    this->_x += this->forwardX;
    this->_y += this->forwardY;
    this->myvisit[_x][_y]++;
}

void Robot::TurnRight(){
    if(this->forwardX == 0 && this->forwardY == 1){
        this->forwardX = -1;
        this->forwardY = 0;
    } else if(this->forwardX == 0 && this->forwardY == -1){
        this->forwardX = 1;
        this->forwardY = 0;
    } else if(this->forwardX == 1 && this->forwardY == 0){
        this->forwardX = 0;
        this->forwardY = 1;
    } else if(this->forwardX == -1 && this->forwardY == 0){
        this->forwardX = 0;
        this->forwardY = -1;
    }    
}

bool Robot::IsFacingWall(const Maze &mz) const {
    int w = this->_x + this->forwardX;
    int h = this->_y + this->forwardY;
    if(mz.IsWall(w, h)){
        return true;
    }
    return false;
}

int Robot::VisitNumber(const int x, const int y) const {
    return this->myvisit[x][y];
}

void Robot::SetLoop_nAndLoc(const int x, const int y){
    this->loopLoc[loop_n][0] = x;
    this->loopLoc[loop_n][1] = y;
    this->loop_n++; 
}

void checkObj(string &s, int row, Robot &bot, Maze &map);
void DEBUG_printAllLoopLocs(const Robot bot);
void DEBUG_printAllVisitNumer(const Robot bot, int w, int h);
int main()
{
    int w, h;
    Maze mymap;
    Robot mybot;
    cin >> w >> h; cin.ignore();
    mymap.InitMaze(w, h);

    long long n;
    cin >> n; cin.ignore();
    for(int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        checkObj(line, i, mybot, mymap);
    }

    int pre_x = mybot.Robot_width();
    int pre_y = mybot.Robot_height();
    int count = 0;
    for(int i = 0; i < n; i++) {
        while((mybot.IsFacingWall(mymap))){
            mybot.TurnRight();
        }
        mybot.GoForward(mymap);

        int x = mybot.Robot_width();
        int y = mybot.Robot_height();
        int check_next = mybot.VisitNumber(x + mybot.Robot_forwardX(), y + mybot.Robot_forwardY());
        if(mybot.VisitNumber(pre_x, pre_y) >= 3){
            if(mybot.VisitNumber(x, y) <= 2 && check_next < 2){
                mybot.SetLoop_nAndLoc(pre_x, pre_y);
                pre_x = x, pre_y = y;
                continue;
            }
            int tmp = (n - i) % mybot.Robot_loopAccount();
            mybot.SetRobotLocation(mybot.Robot_finalX(tmp), mybot.Robot_finalY(tmp));
            break;
        } else if(mybot.VisitNumber(pre_x, pre_y) == 2){
            if(mybot.VisitNumber(x, y) <= 1 && check_next < 1){
                pre_x = x, pre_y = y;
                continue;
            }
            mybot.SetLoop_nAndLoc(pre_x, pre_y);
        }
        pre_x = x, pre_y = y;
    }
// DEBUG_printAllLoopLocs(mybot);
// mymap.PrintMap();
// DEBUG_printAllVisitNumer(mybot, w, h);

    cout << mybot.Robot_width() << " " << mybot.Robot_height() << endl;
}

void DEBUG_printAllLoopLocs(const Robot bot){
    for(int i = 0; i <= bot.Robot_loopAccount()+2; i++){
        printf("x, y: %d, %d\n", bot.Robot_finalX(i), bot.Robot_finalY(i));
    }
    cout << endl;
}

void DEBUG_printAllVisitNumer(const Robot bot, int w, int h){
    for( int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << bot.VisitNumber(j, i) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void checkObj(string &s, int row, Robot &bot, Maze &map) {
    int len = s.length();
    for(int i = 0; i<len; i++){
        if(s[i] == '#'){
            map.SaveWall(i, row);
        }
        else if(s[i] == 'O'){
            bot.SetRobotLocation(i, row);
        }
    }
}

/*
CASE 1：
12 6
987
...#........
...........#
............
............
..#O........
..........#.
---------------------
CASE 2:
5 5
4
#####
#...#
#.#.#
#...#
##O##
---------------------
CASE 3:
16 10
12321123212397
...#...###......
...............#
.#..............
...........#....
................
................
..#O............
.......####.....
#...............
###############.
*/
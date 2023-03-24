#ifndef MYROBOT__
#define MYROBOT__
#include "maze.h"
class Robot
{
public:
    void SetNumOperation(int n) {totalStep = n;};
    void SetRobotLocation(int w, int h);
    int Robot_width()   const { return this->x_; };
    int Robot_height()  const { return this->y_; };
    int Robot_forwardX()   const { return this->forwardX; };
    int Robot_forwardY()  const { return this->forwardY; };
    long long Robot_totalOp() const { return this->totalStep; };
    int VisitNumber(const int x, const int y) const;
    int Robot_loopAccount()         const { return this->loop_n; };
    int Robot_finalX(const int n)   const { return this->loopLoc[n][0]; };
    int Robot_finalY(const int n)   const { return this->loopLoc[n][1]; };

    void GoForward();
    void TurnRight();
    bool IsFacingWall(const Maze &mz) const;
    void SetLoop_nAndLoc(const int x, const int y);

private:
    int x_ = 0;
    int y_ = 0;
    long long totalStep = 1;
    int forwardX = 0;   // initially moves upwards
    int forwardY = -1;  // initially moves upwards

    int myvisit[MAX_WIDTH][MAX_HEIGHT] = {0};
    int loop_n = 0;
    int loopLoc[MAX_WIDTH * MAX_HEIGHT][2] = {0};
};
#endif
#ifndef MYROBOT__
#define MYROBOT__
#include "maze.h"
class Robot
{
public:
    void SetRobotLocation(const int w, const int h);
    int Robot_x()   const { return this->x_; };
    int Robot_y()  const { return this->y_; };
    int Robot_forwardX()   const { return this->forwardX; };
    int Robot_forwardY()  const { return this->forwardY; };
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
    int forwardX = 0;   // initially moves upwards
    int forwardY = -1;  // initially moves upwards
    int dirX[4] = {0, 1, 0, -1};
    int dirY[4] = {-1, 0, 1, 0};
    int dir = 0;
    int myvisit[MAX_WIDTH][MAX_HEIGHT] = {0};
    int loop_n = 0;
    int loopLoc[MAX_WIDTH * MAX_HEIGHT][2] = {0};
};
#endif
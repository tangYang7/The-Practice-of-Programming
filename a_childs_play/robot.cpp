#include "robot.h"
void Robot::SetRobotLocation(const int w, const int h)
{
    this->x_ = w;
    this->y_ = h;
}

void Robot::GoForward()
{
    this->x_ += this->forwardX;
    this->y_ += this->forwardY;
    this->myvisit[x_][y_] += 1;
}
bool Robot::IsFacingWall(const Maze &mz) const
{
    int w = this->x_ + this->forwardX;
    int h = this->y_ + this->forwardY;
    if(mz.IsWall(w, h))
    {
        return true;
    }
    return false;
}

void Robot::TurnRight()
{   
    this->dir = (this->dir + 1) % 4;
    this->forwardX = this->dirX[this->dir];
    this->forwardY = this->dirY[this->dir]; 
}

int Robot::VisitNumber(const int x, const int y) const
{
    return this->myvisit[x][y];
}

void Robot::SetLoop_nAndLoc(const int x, const int y) 
{
    this->loopLoc[loop_n][0] = x;
    this->loopLoc[loop_n][1] = y;
    this->loop_n++; 
}

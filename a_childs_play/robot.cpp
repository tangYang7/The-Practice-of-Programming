#include "robot.h"
void Robot::SetRobotLocation(int w, int h)
{
    this->x_ = w;
    this->y_ = h;
}

void Robot::GoForward()
{
    this->x_ += this->forwardX;
    this->y_ += this->forwardY;
    this->myvisit[x_][y_]++;
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
    if(this->forwardX == 0 && this->forwardY == 1)
    {
        this->forwardX = -1;
        this->forwardY = 0;
    }
    else if(this->forwardX == 0 && this->forwardY == -1)
    {
        this->forwardX = 1;
        this->forwardY = 0;
    }
    else if(this->forwardX == 1 && this->forwardY == 0)
    {
        this->forwardX = 0;
        this->forwardY = 1;
    }
    else if(this->forwardX == -1 && this->forwardY == 0)
    {
        this->forwardX = 0;
        this->forwardY = -1;
    }    
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

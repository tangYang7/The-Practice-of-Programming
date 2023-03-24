#include "maze.h"
void Maze::InitMaze(const int w, const int h)
{
    width_ = w;  
    height_ = h;
}
void Maze::SaveWall(const int w, const int h)
{
    map_[w][h] = 1;
}
void Maze::SaveSpace(const int w, const int h)
{
    map_[w][h] = 2;
}
bool Maze::IsWall(const int w, const int h) const
{
    if(this->map_[w][h] != 1)
        return false;
    return true;
}
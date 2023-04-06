#include "maze.h"
enum {WALL = 1, SPACE = 2};
void Maze::InitMaze(const int w, const int h)
{
    width_ = w;  
    height_ = h;
}
void Maze::SaveWall(const int w, const int h)
{
    map_[w][h] = WALL;
}
void Maze::SaveSpace(const int w, const int h)
{
    map_[w][h] = SPACE;
}
bool Maze::IsWall(const int w, const int h) const
{
    if(this->map_[w][h] != WALL)
        return false;
    return true;
}
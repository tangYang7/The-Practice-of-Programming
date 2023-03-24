#ifndef MAZE__
#define MAZE__

#include <iostream>
#define MAX_WIDTH 22
#define MAX_HEIGHT 12

using namespace std;
class Maze
{
public:
    void InitMaze(const int w, const int h);
    void SaveWall(const int w, const int h);    // 1 in maze map
    void SaveSpace(const int w, const int h);   // 2 in maze map
    bool IsWall(const int w, const int h) const;
    void PrintMaze() const {
        for(int j = 0; j<this->height_; j++){
            for( int i = 0; i<this->width_; i++){
                cout << this->map_[i][j] << " ";
            }
            cout << endl;
        }
    };
    
private:
    int width_ = 0;
    int height_ = 0;
    int map_[MAX_WIDTH][MAX_HEIGHT] = {0};
};
#endif
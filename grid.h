#pragma once
#include <vector>
#include "include/raylib.h"

class Grid
{
public:
     Grid(int row = 20, int col = 10, int cellSize = 30);
     ~Grid();
     int** grid;
     void intialize();
     void Print();
     void Draw();
     
private:
     int numRows;
     int numCols;
     int cellSize;
     std::vector<Color> colors;
};
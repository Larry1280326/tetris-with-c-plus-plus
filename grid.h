#pragma once
#include <vector>
#include "include/raylib.h"

class Grid
{
public:
     Grid(int row = 20, int col = 10, int cellSize = 30);
     ~Grid();
     void intialize();
     void Print();
     void Draw();
     bool IsCellOutside(int row, int column);
     bool IsCellEmpty(int row, int column);
     int ClearFullRows();
     int** grid;
private:
     bool IsRowFull(int row);
     void ClearRow(int row);
     void MoveRowDown(int row, int numRows);
     int numRows;
     int numCols;
     int cellSize;
     std::vector<Color> colors;
};
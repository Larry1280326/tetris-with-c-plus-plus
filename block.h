#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "color.h"

class Block{
public:
     Block();
     void Draw();
     void Move(int row, int column);
     std::vector<Position> GetCellPositions();
     int id;
     std::map<int, std::vector<Position>> cells;
private:
     int cellSize;
     int rotationState;
     std::vector<Color> colors;
     int rowOffset;
     int columnOffset;
};
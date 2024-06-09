#include "grid.h"
#include <iostream>
#include "color.h"

Grid::Grid(int row, int col, int cellSize)
: numRows(row), numCols(col), cellSize(cellSize)
{
     intialize();
     colors = GetCellColors();
}

Grid::~Grid(){
     for (int i=0; i<numRows; ++i){
          delete [] grid[i];
     }
     delete [] grid;
}

void Grid::intialize()
{
     grid = new int*[numRows];
     for (int i =0; i<numRows; ++i){
          grid[i] = new int[numCols];
          for (int j =0; j<numCols; ++j){
               grid[i][j] = 0;
          }
     }
}

void Grid::Print()
{
     for (int i=0; i<numRows; ++i){
          for (int j=0; j<numCols; ++j){
               std::cout<< grid[i][j] << ' ';
          }
          std::cout<< std::endl;
     }
}


void Grid::Draw()
{
     for (int i =0; i<numRows; ++i){
          for (int j=0; j<numCols; ++j){
               int cellValue = grid[i][j];
               DrawRectangle(j*cellSize +1, i*cellSize +1, cellSize -1, cellSize -1, colors[cellValue]);
          }
     }
}
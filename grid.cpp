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
               DrawRectangle(j*cellSize +11, i*cellSize +11, cellSize -1, cellSize -1, colors[cellValue]);
          }
     }
}

bool Grid::IsCellOutside(int row, int column)
{
     if (row >= 0 && row < numRows
          && column >=0 && column < numCols){
          return false;
     }
     return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
     if (grid[row][column] == 0){
          return true;
     }
     return false;
}

int Grid::ClearFullRows()
{
     int completed = 0;
     for (int i = numRows -1; i>=0 ; --i){
          if (IsRowFull(i)){
               ClearRow(i);
               ++completed;
          }
          else if (completed){
               MoveRowDown(i, completed);
          }
     }
     return completed;
}

bool Grid::IsRowFull(int row)
{
     for (int j=0; j<numCols; ++j){
          if (!grid[row][j]){
               return false;
          }
     }
     return true;
}

void Grid::ClearRow(int row)
{
     for (int j=0; j< numCols; ++j){
          grid[row][j] = 0;
     }
}

void Grid::MoveRowDown(int row, int numRows)
{
     for (int j=0; j<numCols; ++j){
          grid[row+numRows][j] =  grid[row][j];
          grid[row][j] = 0;
     }
}

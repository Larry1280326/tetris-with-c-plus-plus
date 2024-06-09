#include "game.h"
#include <random>

Game::Game()
: blocks(GetAllBlocks()), 
currentBlock(GetRandomBlock()), 
nextBlock(GetRandomBlock()),
gameOver(false),
score(0)
{}

Block Game::GetRandomBlock(){
     if (blocks.empty()){
          blocks = GetAllBlocks();
     }
     int randomIndex = rand() % blocks.size();
     Block block = blocks[randomIndex];
     blocks.erase(blocks.begin() + randomIndex);
     return block;
}

std::vector<Block> Game::GetAllBlocks(){
     return {TBlock(), JBlock(), LBlock(), OBlock(), SBlock(), ZBlock()};
}

void Game::Draw(){
     grid.Draw();
     currentBlock.Draw();
}

void Game::HandleInput()
{
     int keyPressed = GetKeyPressed();
     if (gameOver && keyPressed != 0){
          gameOver = false;
          Reset();
     }
     switch(keyPressed){
          case KEY_A:
               MoveBlockLeft();
               break;
          case KEY_D:
               MoveBlockRight();
               break;
          case KEY_S:
               MoveBlockDown();
               updateScore(0, 1);
               break;
          case KEY_W:
               RotateBlock();
               break;
     }
}

void Game::MoveBlockLeft(){
     if (!gameOver){
     currentBlock.Move(0, -1);
     if (IsBlockOutside()|| !BlockFits()){
          currentBlock.Move(0, 1);
     }
     }
}

void Game::MoveBlockRight(){
     if (!gameOver){
     currentBlock.Move(0, 1);
     if (IsBlockOutside()|| !BlockFits()){
          currentBlock.Move(0, -1);
     }
     }
}

void Game::MoveBlockDown(){
     if (!gameOver){
     currentBlock.Move(1, 0);
     if (IsBlockOutside() || !BlockFits()){
          currentBlock.Move(-1, 0);
          lockBlock();
     }
     }
}

bool Game::IsBlockOutside()
{
     std::vector<Position> tiles = currentBlock.GetCellPositions();
     for (Position item: tiles){
          if (grid.IsCellOutside(item.row, item.column)){
               return true;
          }
     }
     return false;
}

void Game::RotateBlock()
{
     if (!gameOver){
     currentBlock.Rotate();
     if (IsBlockOutside()){
          currentBlock.UndoRotation();
     }
     }
}

void Game::lockBlock()
{
     std::vector<Position> tiles = currentBlock.GetCellPositions();
     for (Position item: tiles){
          grid.grid[item.row][item.column] = currentBlock.id;
     }
     currentBlock = nextBlock;
     if (!BlockFits()){
          gameOver = true;
     }
     nextBlock = GetRandomBlock();
     int rowsCleared = grid.ClearFullRows();
     updateScore(rowsCleared, 0);
}

bool Game::BlockFits()
{
     std::vector<Position> tiles = currentBlock.GetCellPositions();
     for (Position item: tiles){
          if (!grid.IsCellEmpty(item.row, item.column)){
               return false;
          }
     }
     return true;
}

void Game::Reset()
{
     grid.intialize();
     blocks = GetAllBlocks();
     currentBlock = GetRandomBlock();
     nextBlock = GetRandomBlock();
     score = 0;
}

void Game::updateScore(int linesCleared, int moveDownPoints)
{
     switch(linesCleared){
          case 1:
               score +=100; 
               break;
          case 2:
               score +=300;
               break;
          case 3:
               score+=500;
               break;
          default:
               break;
     }
     score+= moveDownPoints;
}

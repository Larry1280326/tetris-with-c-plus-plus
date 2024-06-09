#include "game.h"
#include <random>

Game::Game(): blocks(GetAllBlocks()), currentBlock(GetRandomBlock()), nextBlock(GetRandomBlock()){}

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

void Game::HandleInput(){

}

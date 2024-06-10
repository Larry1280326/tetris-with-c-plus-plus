# platform
The testing platform is Apple M2 MacBook Air (MacOS 14.4.1) with compiler g++-13 (Homebrew GCC 13.2.0) 13.2.0. I don't have a Windows and Linux device on my hand right now.

# introduction
This is a simplified version of [Tetris](https://en.wikipedia.org/wiki/Tetris) written in the programming language C++ with [`raylib` library](https://www.raylib.com/). 

# command for compilation
`g++ -std=c++11 *.cpp   -L lib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a -o tetris`

# run the game
`./tetris`

# instruction
* Press `D`: move to the right by one unit
* Press `A`: move to the left by one unit
* Press `S`: move downward by one unit
* Press `W`: rotate the block

# simplified scoring system
* $100$ points for a single line clear
* $300$ points for a double line clear
* $500$ points for a triple line clear
* $1$ points for each move down by the player
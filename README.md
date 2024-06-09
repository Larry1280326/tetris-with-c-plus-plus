# command for compilation
`g++ -std=c++11 *.cpp   -L lib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a -o tetris`

# run the game
`./tetris`

# Simplified Scoring System
* $100$ points for a single line clear
* $300$ points for a double line clear
* $500$ points for a triple line clear
* $1$ points for each move down by the player
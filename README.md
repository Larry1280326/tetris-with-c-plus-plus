# command for compilation
`g++ -std=c++11 *.cpp   -L lib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a -o tetris`

# run the game
`./tetris`
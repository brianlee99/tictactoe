tictactoe: main.o Game.o Board.o Square.o
	g++ -g -std=c++11 -o  tictactoe main.o Game.o Board.o Square.o  # -g for gdb

main.o: main.cpp
	g++ -c -std=c++11 -g main.cpp

Game.o: Game.cpp Game.h
	g++ -c -std=c++11 -g Game.cpp

Board.o: Board.cpp Board.h
	g++ -c -std=c++11 -g Board.cpp

Square.o: Square.cpp Square.h
	g++ -c -std=c++11 -g Square.cpp

clean:
	rm *.o tictactoe

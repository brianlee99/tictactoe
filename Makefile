tictactoe: main.o Game.o Board.o Square.o
	g++ -g -o tictactoe main.o Game.o Board.o Square.o  # for gdb

main.o: main.cpp
	g++ -c -g main.cpp

Game.o: Game.cpp Game.h
	g++ -c -g Game.cpp

Board.o: Board.cpp Board.h
	g++ -c -g Board.cpp

Square.o: Square.cpp Square.h
	g++ -c -g Square.cpp

clean:
	rm *.o tictactoe
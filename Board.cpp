#include "Board.h"

Board::Board() {
    for (int i = 0; i < 3; i++) {
        vector<Square> v(3);
        // for (int j = 0; j < 3; j++) {
        //     v[j] = Square(' ');
            
        // }
        squares.push_back(v);
    }
}

char Board::getSquare(int x, int y) {
    return squares[x][y].getState();
}

void Board::setSquare(int x, int y, char newState) {
    squares[x][y].setState(newState);
}
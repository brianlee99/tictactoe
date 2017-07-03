#pragma once
#include "Square.h"
#include <vector>
using namespace std;

class Board {
public:
	Board();
    char getSquare(int x, int y);
    void setSquare(int x, int y, char newState);
private:
    vector< vector<Square> > squares;  //2d vector of squares
};
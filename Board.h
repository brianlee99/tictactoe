#pragma once
#include "Square.h"
#include <vector>
using namespace std;

class Board {
public:
	Board();
    char at(int x, int y);
    void set(int x, int y, char newState);
private:
    vector< vector<Square> > squares;  //2d vector of squares
};
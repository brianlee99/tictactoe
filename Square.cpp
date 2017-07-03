#include "Square.h"
#include <iostream>
using namespace std;
Square::Square() {
    state = ' '; // by default
}

Square::Square(char s) {
    state = s;
}

char Square::getState() {
    return state;
}

void Square::setState(char newState) {
    state = newState;
}

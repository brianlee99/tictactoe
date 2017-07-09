#include "Square.h"

Square::Square(char s) {
    state = s;
}

char Square::getState() {
    return state;
}

void Square::setState(char newState) {
    state = newState;
}
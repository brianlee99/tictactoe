#pragma once

class Square {
public:
	Square() : state(' ') {};
    Square(char s);
	char getState();
	void setState(char newState);
private:
	char state; // 'X', 'O', or ' '

};
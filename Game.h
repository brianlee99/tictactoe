#pragma once
#include "Board.h"
//#include "Square.h"
//#include <vector>
//using namespace std;

class Game {
public:
    Game(); // don't really need to do anything here; default Board constructor is called already(?)
    void setup();
    void setPlayerAsX(); 
    void setPlayerAsO();
    void initialize();
    void play();
    void clearBoard();
    char getSquare(int x, int y);
    int checkForWin(int currPlayer, char marker, int x, int y);
    void playerWins();
    void aiWins();
    void draw();
    void setSquare(int x, int y, char marker);
    void printBoard();
    vector<int> playerTurn(char marker);
    vector<int> aiTurn(char marker) ;
    bool isTaken(int x, int y);


private:
    Board board;
    int nextPlayer;            // 1 for player, 2 for ai; irrespective of marker type
    char playerMarker;         // marker is either 'X' or 'O'
    char aiMarker;
    //int winner;
    int turn;

    int p_wins;
    int a_wins;
    int draws;
    // player1: X, and x always goes first
    // player2: O
    // -1 means there is not yet a next player (game is over or hasn't started)
};
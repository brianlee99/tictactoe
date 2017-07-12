#pragma once
#include "Board.h"
#include "Square.h"
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
    char at(int x, int y);
    int checkForWin(int currPlayer, char marker, int x, int y);
    void playerWins();
    void aiWins();
    void draw();
    void set(int x, int y, char marker);
    void printBoard();
    vector<int> playerTurn(char marker);
    vector<int> aiTurn(char marker) ;
    bool isTaken(int x, int y);

    vector<int> findWinningPlay(const vector< vector<int> > & line);
    vector<int> preventLosingPlay(const vector< vector<int> > & line);
    vector<int> playRandom();
    vector<int> playCorner();
    
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
    
    vector < vector< vector <int> > > lines; // 
};
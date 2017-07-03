#include "Game.h"

//#include "Square.h"
#include <iostream>
#include <vector>
using namespace std;


Game::Game() {
    nextPlayer = -1;
    //winner = -1;
    turn = -1;

    p_wins = 0;
    a_wins = 0;
    draws = 0;

    setup();
}

// allows the user to choose which marker to play as, then starts the game
void Game::setup() {
    cout << "Welcome to Tic Tac Toe for C++" << endl;
    cout << "Created by Brian Lee, 2017\n" << endl;
    cout << "Please choose a marker:" << endl;
    cout << "1. X" << endl;
    cout << "2. O" << endl;

    // 1 -> X, 2 -> O (X always goes first)
    int choice;
    cin >> choice;

    // continue prompting until user supplies a valid choice
    while (choice != 1 && choice != 2) {
        cout << "Please choose a marker" << endl;
        cout << "1. X\n2. O" << endl;
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Invalid selection" << endl;
        }
    }

    // choice is either 1 or 2, check:
    if (choice == 1) {
        setPlayerAsX();
    } else if (choice == 2) {
        setPlayerAsO();
    }

    // Start the game


    // keep going
    while(1) {     
        initialize();
        play();
    }
}

void Game::setPlayerAsX() {
    cout << "You have selected X" << endl;
    cout << "You will go first\n" << endl;
    playerMarker = 'X';
    aiMarker = 'O';
}

void Game::setPlayerAsO() {
    cout << "You have selected O" << endl;
    cout << "You will go second\n" << endl;
    playerMarker = 'O';
    aiMarker = 'X';
}

// Initializes the game 
void Game::initialize() {
    clearBoard();
    // if player is 'X', then player goes first (1), otherwise
    // AI goes first (2)
    nextPlayer = (playerMarker == 'X') ? 1 : 2;

    turn = 1;
}

// play enters a while-loop until a winner is decided (or tie occurs)
// then we go back into setup; initialize the settings again,
// then start another round
void Game::play() {
    // winner:
    // 0 if game is ongoing
    // 1 if x wins 
    // 2 if o wins 
    // 3 if draw 
    int winner = 0;

    while (winner == 0) {
        if (nextPlayer == 1) { // player urn
            cout << "It's your move." << endl;
            cout << "Place a marker (e.g. 1 2)" << endl;
            printBoard();

            vector<int> choice = playerTurn(playerMarker);
            
            cout << "You have placed a marker on " << choice[0];
            cout << "," << choice[1] << "\n---" << endl;

            winner = checkForWin(1, playerMarker, choice[0], choice[1]); // passing in 1 for player (i.e. does the player win)
        } else if (nextPlayer == 2) {
            cout << "It's the AI's move." << endl;
            vector<int> choice = aiTurn(aiMarker);

            cout << "The AI has placed a marker on " << choice[0];
            cout << "," << choice[1] << "\n---" << endl;

            winner = checkForWin(2, aiMarker, choice[0], choice[1]);
        }

        // go to the next player 
        if (nextPlayer == 1) {
            nextPlayer = 2;
        } else if (nextPlayer == 2) {
            nextPlayer = 1;
        }
    }

    if (winner == 1) {
        playerWins();
    } else if (winner == 2) {
        aiWins();
    } else if (winner == 3) {
        draw();
    }
}

void Game::clearBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board.setSquare(i, j, ' ');
}

// returns 'X', 'O', or ' '
char Game::getSquare(int x, int y) {
    return board.getSquare(x, y);
}

// returns currPlayer (1 for player, 2 for ai), which is designated as winner
// otherwise, returns 0 (if game has not yet been decided)
// or 3 (if the game resulted in a draw)
int Game::checkForWin(int currPlayer, char marker, int x, int y) {
    // algorithm: check the row and column; corner case are the corner places and middle

    // 1. check if (x, 0), (x, 1), (x, 2) are all marker
    if (getSquare(x, 2) == marker &&
        getSquare(x, 1) == marker &&
        getSquare(x, 0) == marker) {
        // declare winner
        return currPlayer;
    }

    // 2. check if (0, y), (1, y), (2, y) are all marker
    if (getSquare(0, y) == marker &&
        getSquare(1, y) == marker &&
        getSquare(2, y) == marker) {
        // declare winner
        return currPlayer;
    }

    // if x+y is even, then must check appropriate diagonal cases
    if ((x+y) % 2 == 0) {
        if (x + y == 2) {
            // 3. check if (0, 2), (1, 1), (2, 0) are marker
            if (getSquare(0, 2) == marker &&
                getSquare(1, 1) == marker &&
                getSquare(2, 0) == marker) {
                // declare winner
                return currPlayer;
            }
            if (x == 1) { // of course y is 1
                // 4a. check if (0, 0), (1, 1), (2, 2) are marker
                if (getSquare(0, 0) == marker &&
                    getSquare(1, 1) == marker &&
                    getSquare(2, 2) == marker) {
                    // declare winner
                    return currPlayer;
                }
            }
        } else {
            // 4b. check if (0, 0), (1, 1), (2, 2) are marker
            if (getSquare(0, 0) == marker &&
                getSquare(1, 1) == marker &&
                getSquare(2, 2) == marker) {
                // declare winner
                return currPlayer;
            }
        }
    }

    // If all the above checks failed, then either
    // a) There is not yet a decided winner or 
    // b) there is a draw
    // check for a draw by looking at turns
    if (turn == 9) {
        return 3;
    } else {
        return 0;
    }
}

void Game::playerWins() {
    cout << "\n\n\nYou win!\n\n\n" << endl;
    cout << "starting a new game" << endl;
    p_wins++;
}

void Game::aiWins() {
    cout << "\n\n\nSorry, the AI won this one.\n\n\n" << endl;
    cout << "starting a new game" << endl;
    a_wins++;
}

void Game::draw() {
    cout << "\n\n\nIt's a draw, baby!\n\n\n" << endl;
    cout << "starting a new game" << endl;
    draws++;
}

void Game::setSquare(int x, int y, char marker) {
    board.setSquare(x, y, marker);
}

void Game::printBoard() {
    cout << "#############" << endl;
    cout << "# " << getSquare(0, 0) << " # " << getSquare(0, 1) << " # " << getSquare(0, 2) << " #" << endl;
    cout << "#############" << endl;
    cout << "# " << getSquare(1, 0) << " # " << getSquare(1, 1) << " # " << getSquare(1, 2) << " #" << endl;
    cout << "#############" << endl;
    cout << "# " << getSquare(2, 0) << " # " << getSquare(2, 1) << " # " << getSquare(2, 2) << " #" << endl;
    cout << "#############" << endl;
}

vector<int> Game::playerTurn(char marker) {
    // How should the user specify their input?
    int x, y;
    cin >> x >> y;
    bool occupied = isTaken(x, y);

    // Check that x and y are within acceptable limits (betwen 0 and 2)
    while (x > 2 || x < 0 || y > 2 || y < 0 || occupied) {
        if (occupied) {
            cout << "This square is currently occupied." << endl;
            cout << "Please input another x,y value." << endl;
        } else {
            cout << "Please specify proper x and y values" << endl;
        }
        cin >> x >> y;
        occupied = isTaken(x, y);
    }

    setSquare(x, y, marker);

    vector<int> choice(2);
    choice[0] = x;
    choice[1] = y;
    return choice;
}

vector<int> Game::aiTurn(char marker) {
    // it depends on whether AI is x or O
    // TODO: This part.
    bool found = false;
    int x, y;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            // just iterate, and see if it's taken or not
            if (!isTaken(i, j)) {

                x = i;
                y = j;

                // break out of the inner loop
                found = true;
                break;
            }

        }
        // break out of the outer loop
        if (found) {
            break;
        }
    }
    setSquare(x, y, marker);

    vector<int> choice(2);
    choice[0] = x;
    choice[1] = y;
    return choice;
}

bool Game::isTaken(int x, int y) {
    char z = getSquare(x, y);
    if (z == 'X' || z == 'O') {
        return true;
    } else {
        return false;
    }
}


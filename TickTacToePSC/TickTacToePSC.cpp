#include <iostream>

using namespace std;

/* Constants (no magic number)*/
const int EMPTY = 0;
const int PX = 1;
const int PY = 4;
const int ROW = 3;
const int MAXMOVES = 9;
const int BOARDSIZE = 3;

// STUB FOR LATER
void PrintBoard(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    cout << a << " | ";
}
char PP(int player) {
    char charPlayerSymbol = '*';
    if (player == PX) {
        charPlayerSymbol = 'X';
    }
    else if (player == PY) {
        charPlayerSymbol = 'Y';
    }
    return charPlayerSymbol;
}


int IdentifyWinner(int t, int s, int u) {
    int winner = EMPTY;
    int v = t + s + u;
    if (v == (ROW * PX)) {
        winner = PX;
    }
    else if (v == (ROW * PY)) {
        winner = PY;
    }
    return winner;
}



bool WinnerExists(int boardcopy[][BOARDSIZE]) {
    bool boolWinnerExists = false;

    
    for (int i = 0; i < BOARDSIZE; i++) {
        int columnwin[BOARDSIZE];
        int rowwin = 0;
        for (int j = 0; j < BOARDSIZE; j++) {
            rowwin += boardcopy[i][j];
            // COLUMN ADD -- THIS IS WRONG. THINK ABOUT IT.
            // WE ENDED HERE
            if (i == j) {
                columnwin[j] += boardcopy[i][j];
            }
        }
        if ((rowwin == PX * BOARDSIZE) || (rowwin == PY * BOARDSIZE)) {
            boolWinnerExists = true;
        }
    }


    // IGNORE BELOW THIS RIGHT NOW
    int intWinnerNumber = IdentifyWinner(t, s, u);
    if ((intWinnerNumber == PX) || (intWinnerNumber == PY)) {
        boolWinnerExists = true;
    }
    else {
        boolWinnerExists = false;
    }
    return boolWinnerExists;
}

int main()
{
    /*
    The Board
    a | b | c
    ---------
    e | f | g
    ---------
    h | i | j
    */

    /* The Array Board 
    00 | 01 | 02
    10 | 11 | 12
    20 | 21 | 22
    */

    /* Win Conditions
    
    a,b,c
    e,f,g
    h,i,j
    a,e,h
    b,f,i
    c,g,j
    a,f,j
    c,f,h
    
    */

    /* Variable Declarations */
    int intWinStatus = 0;
    bool boolHaveWinner = false;
    int intMoveTracker = 0;
    int board[BOARDSIZE][BOARDSIZE];
    int playerOne;
    int playerTwo;
    // STUB Write some randomizer code 
    // For right now, hard-code it
    playerOne = PX;
    playerTwo = PY;
    // Eliminate the coe above when randomization is done.

    bool boolKeepRunning = true;
    while (boolKeepRunning) {

        int intPlayerOneMove = 0;

        bool boolContinueMoveLoop = true;
        /* Might be a good place for "do while" */
        while (boolContinueMoveLoop) {
            cout << "Player One, please select a move: ";

            // TODO: Show the current board.
            cin >> intPlayerOneMove;
            // TODO: Validation Loop (Correct value for board)
            // TODO: Check validity of move (space must be blank)
        }




        /* Check Win Condition*/

        if (WinnerExists(a, b, c)) {
            intWinStatus = IdentifyWinner(a, b, c);
        }
        else if (WinnerExists(e, f, g)) {
            intWinStatus = IdentifyWinner(e, f, g);
        }
        else if (WinnerExists(h, i, j)) {
            intWinStatus = IdentifyWinner(h, i, j);
        }
        else if (WinnerExists(a, e, h)) {
            intWinStatus = IdentifyWinner(a, e, h);
        }
        else if (WinnerExists(b, f, i)) {
            intWinStatus = IdentifyWinner(b, f, i);
        }
        else if (WinnerExists(c, g, j)) {
            intWinStatus = IdentifyWinner(c, g, j);
        }
        else if (WinnerExists(a, f, j)) {
            intWinStatus = IdentifyWinner(a, f, j);
        }
        else if (WinnerExists(c, f, h)) {
            intWinStatus = IdentifyWinner(c, f, h);
        }

        intMoveTracker++;
        if ((intMoveTracker > MAXMOVES) || (intWinStatus == PX) || (intWinStatus == PY))   {
            boolKeepRunning = false;
        }
    }


    
    intWinStatus = IdentifyWinner(a, e, i);

    if (intWinStatus == PX) {
        cout << "X Has Won";
    }
    else if (intWinStatus == PY) {
        cout << "Y Has Won";
    }

    return 0;
}


#include <iostream>

using namespace std;

const int EMPTY = 0;
const int PX = 1;
const int PY = 4;
const int ROW = 3;

int WinCondition(int t, int s, int u) {
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


    int a, b, c, d, e, f, g, h, i = EMPTY; /* Mass initialization */
    a = b = c = d = e = f = g = h = i; /* Works on ints or any time we pass by VALUE not reference.*/



    int winStatus = 0;
    winStatus = WinCondition(a, e, i);

    if (winStatus == PX) {
        cout << "X Has Won";
    }
    else if (winStatus == PY) {
        cout << "Y Has Won";
    }

    return 0;
}


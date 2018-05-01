// George Strauch
// ticTacToe
// 5/1/2018


/* uses a 2d char array to play tic tic-tac-toe
 * clears the board then alternates between x and o
 * player just needs to input position*/


#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int const intX = 3;
int const intY = 3;


void setBoard(char chrAry[intY][intX]){
    for (int i = 0; i < intY; ++i) {
        for (int j = 0; j < intX; ++j) {
            chrAry[i][j] = '-';
        }
    }

} //


void print(char chrAry[intY][intX]){
    cout << "  ";
    for (int i = 1; i < intY + 1; ++i){
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < intY; ++i) {
        cout << i+1 << " ";
        for (int j = 0; j < intX; ++j) {
            cout <<  chrAry[i][j] << " ";
        }
        cout << endl;
    }

} //


// x and y are 1-3
void setChar(char chrAry[intY][intX], int x, int y, char charInput){
    chrAry[y-1][x-1] = charInput;
} //


bool testDown(char chrAry[intY][intX], char chr){

    bool boltmp = true;
    for (int j = 0; j < intX; ++j) {

        for (int i = 0; i < intY; ++i) {
            if(chrAry[i][j] != chr){
                boltmp = false;
                break;
            }
        }

        if(boltmp){
            cout << "The winner is " << chr;
            cerr << " test down";
            return true;
        }
        boltmp = true;
    }
    return false;

} //


bool testAcross(char chrAry[intY][intX], char chr){

    bool boltmp = true;
    for (int i = 0; i < intY; ++i) {

        for (int j = 0; j < intX; ++j) {
            if(chrAry[i][j] != chr){
                boltmp = false;
                break;
            }
        }

        if(boltmp){
            cout << "The winner is " << chr;
            cerr << " test across";
            return true;
        }
        boltmp = true;
    }
    return false;

} //


bool testDiagRight(char chrAry[intY][intX], char chr){

    for (int j = 0; j < 3; ++j) {

        if(chrAry[j][j] != chr){
            return false;
        }
    }
    cout << "The winner is " << chr;
    cerr << " test diag right";
    return true;

} //


bool testDiagLeft(char chrAry[intY][intX], char chr){

    for (int j = 3; j > 0; --j) {

        if(chrAry[j][j] != chr){
            return false;
        }
    }
    cout << "The winner is " << chr;
    cerr << " test diag left";
    return true;

} //


bool winner(char chrAry[intY][intX]){

    if(testAcross(chrAry, 'X') || testAcross(chrAry, 'O')){
        return true;
    }
    else if (testDown(chrAry, 'X') || testDown(chrAry, 'O')){
        return true;
    }
    else if(testDiagRight(chrAry, 'X') || testDiagRight(chrAry, 'O')){
        return true;
    }
    else if(testDiagLeft(chrAry, 'X') || testDiagLeft(chrAry, 'O')){
        return true;
    }
    else{ return false; }

} //


void go(char charGame[intY][intX], char chrPlayer){

    string strPosition;
    int x = 0;
    int y = 0;

    cout << "player " << chrPlayer << " go, enter position " << endl;
    cin >> strPosition;
    x = strPosition.at(0) - 48;     //this makes input easier
    y = strPosition.at(1) - 48;     //the user input is actually a char cast into ascii value
                                    //then subtract the offset (ascii value for '0' is 48) then cast back into an int
    cout << "entering " << chrPlayer << " at position " << x << "," << y << endl;

    setChar(charGame, x, y, chrPlayer);
    print(charGame);

} //


int main() {

    char charGame[intY][intX];
    setBoard(charGame);

    cout << endl << "Input example: 22 for the middle space" << endl << endl;

    while (!winner(charGame)){
        go(charGame, 'X');
        if(winner(charGame)){
            break;
        }
        go(charGame, 'O');
    }

    return 0;
} //
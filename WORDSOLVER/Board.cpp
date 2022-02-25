#include "board.h"

using namespace std;

//using namespace std;

int offsetSurround[8][2] = { {0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1} };

//constructor initialising
board::board(Trie * dictionary, int size, string characters) {
    this -> dictionary = dictionary;
    this -> characters = characters;
    this -> size = size;
};

bool board::isValidPosition(int y, int x) {
    if (y < 0 || y >= size) return false;
    if (x < 0 || x >= size) return false;
    return true;
}

//use passedValues to encode values already used 
void board::dp(int position, int passedValues, string word) {
    word += characters[position];

    if (!dictionary->startsWith(word)) return; // if there are no possible words to make, skip.

    if (dictionary->search(word)) solutions.push_back(word);// if a word in dict, add to dict.


    passedValues = (1 << position) | passedValues;

    int y = position / size;
    int x = position % size;
    int tmpx = x, tmpy = y, tmpPosition, tmpPassedValues;
    for (int i = 0; i < 8; i++) {
        tmpx = x + offsetSurround[i][0];
        tmpy = y + offsetSurround[i][1];
        tmpPosition = tmpy * size + tmpx;
        //checking if position is valid;
      //bitmask to check if position is not already in passed values
        // if valid && not oob/wrapping around;
        if (isValidPosition(tmpy, tmpx)&&!((max(tmpy,y)==size-1 &&min(tmpy,y) == 0 )|| (max(tmpx, x) == size - 1 && min(tmpx, x) == 0))) {
            tmpPassedValues = 1 << tmpPosition;
            if ((tmpPassedValues & passedValues) == 0) {
                dp(tmpPosition, tmpPassedValues | passedValues, word);
            }
        }
    }
    return;
};



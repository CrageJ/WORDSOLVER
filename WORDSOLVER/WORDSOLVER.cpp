// WORDSOLVER.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "board.h"
#include "trie.h"
#include <algorithm>
#include <fstream>
//using namespace std;

int main() {
    //create dictionary in trie
    auto t = new Trie();
    string line;
    ifstream dict;
    dict.open("dictionary.txt");
    if (dict.is_open()) {
        while (dict >> line) {
            t->insert(line);
        }
        dict.close();
    }
    //create input, board, and solve
    int boardSize = 4;
    std::string characters;
    std::cout << "\nInput Characters\n";
    std::cin>>characters;
    for (auto& c : characters) c = toupper(c);
    board* S = new board(t, boardSize, characters);

    for (int i = 0; i < S->size*S->size; i++) {
        S->dp(i, 0, "");
    }

    sort(S->solutions.begin(), S->solutions.end());
    S->solutions.erase(std::unique(S->solutions.begin(), S->solutions.end()), S->solutions.end());

    sort(S->solutions.begin(), S->solutions.end(), []
    (const std::string& first, const std::string& second) {
            return first.size() < second.size();
        });


    for (auto i : S->solutions) {
        if (i.size() > 3) {
            cout << i<<endl;
        }
    }

    std::cout << "END OF PROGRAM";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

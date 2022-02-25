#pragma once
#include <iostream>
#include <vector>
#include "trie.h"

using namespace std;

struct board {

	board(Trie * dictionary, int size, string characters);

	Trie * dictionary;
	int size; 
	string characters;
	vector<string> solutions;

	bool isValidPosition(int y, int x);
	void dp(int position, int passedValues, string word);
};






#pragma once
#include <string>
#include <iostream>

const int ALPHABET_SIZE = (26);
const int CHAR_OFFSET = (int)('A'); // capslock matter

using namespace std;

struct TrieNode {
	TrieNode();

	TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};

struct Trie {
	Trie(); //Initializes the trie object.

	TrieNode * root;

	void insert(string word); //Inserts the string word into the trie.
	bool search(string word);// Returns true if the string word is in the trie(i.e., was inserted before), and false otherwise.
	bool startsWith(string prefix);
};
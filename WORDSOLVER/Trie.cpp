#include "trie.h"
#include <cassert>
using namespace std;


TrieNode::TrieNode() {
    isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = NULL;
    }
}

Trie::Trie() {
    root = new TrieNode();
    root->isEndOfWord = false;
}

void Trie::insert(string word) {
    if (word == "") return;
    int wordLength = word.size(), i = 0, charIndexValue;
    TrieNode* currentNode = root;
    assert(root != NULL);
    while (i < wordLength) {
        charIndexValue = word[i] - CHAR_OFFSET;
        if (currentNode->children[charIndexValue] == NULL) {
            currentNode->children[charIndexValue] = new TrieNode();
        }
        currentNode = currentNode->children[charIndexValue];
        i++;
    }
    currentNode->isEndOfWord = true;
    return;
}

bool Trie::search(string word) {
    if (word == "") return false;
    int wordLength = word.size(), i = 0, charIndexValue;
    TrieNode* currentNode = root;
    assert(root != NULL);
    while (i < wordLength) {
        charIndexValue = word[i] - CHAR_OFFSET;
        currentNode = currentNode->children[charIndexValue];
        if (currentNode == NULL) {
            return false;
        }
        i++;

    }

    return currentNode->isEndOfWord;
}

bool Trie::startsWith(string prefix) {
    if (prefix == "") return false;
    int wordLength = prefix.size(), i = 0, charIndexValue;
    TrieNode* currentNode = root;
    assert(root != NULL);
    while (i < wordLength) {
        charIndexValue = prefix[i] - CHAR_OFFSET;
        currentNode = currentNode->children[charIndexValue];
        if (currentNode == NULL) {
            return false;
        }
        i++;

    }
    return true;
};





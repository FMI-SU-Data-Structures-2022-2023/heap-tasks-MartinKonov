#include "solution.h"

Trie::Trie() {

    this->first = new TrieNode;

}

bool Trie::LetterExists(const char letter, TrieNode* curTrie) {

    if (!curTrie->alphabet[letter - 97]) {
        return false;
    }
    return true;
}


void Trie::insert(const char* word) {
    int index = 0;
    TrieNode* cur = this->first;

    while (true) {
        
        if (word[index + 1] == '\0') {

            cur->alphabet[word[index] - 97] = new TrieNode;
            cur = cur->alphabet[word[index] - 97];
            cur->endOfWord = true;
            break;
        }

        if (LetterExists(word[index], cur)) {
            cur = cur->alphabet[word[index] - 97];
            index++;
        }
        else {
            cur->alphabet[word[index] - 97] = new TrieNode;
            cur = cur->alphabet[word[index] - 97];
            index++;
        }

    }

};


bool Trie::search(const char* word) {
    int index = 0;
    TrieNode* cur = this->first;

    while (word[index] != '\0') {

        if (LetterExists(word[index], cur)) {

            cur = cur->alphabet[word[index] - 97];
            index++;
            continue;
        }

        return false;

    }
    if (cur->endOfWord) {
        return true;
    }
    return false;

};

//void Trie::ClearAllNodes(TrieNode* node) {
//
//    if (isLeaf(node)) {
//        node->endOfWord = false;
//        delete node;
//        return;
//    }
//
//    for (size_t i = 0; i < 26; i++)
//    {
//        if (node->alphabet[i]) {
//            ClearAllNodes(node->alphabet[i]);
//        }
//
//    }
//
//}
//
//bool Trie::isLeaf(TrieNode* node) {
//
//    for (size_t i = 0; i < 26; i++)
//    {
//        if (node->alphabet[i]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//Trie::~Trie() {
//
//
//    ClearAllNodes(this->first);
//
//}

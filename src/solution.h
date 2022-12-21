#ifndef WEEK7_TREE_H
#include <cstddef>

class Trie {

    struct TrieNode {
        bool endOfWord;
        TrieNode* alphabet[26];

        TrieNode() {
            endOfWord = false;
            for (size_t i = 0; i < 26; i++)
            {
                alphabet[i] = nullptr;
            }
        }
    };
    
    TrieNode* first;

public:
    Trie();
    void ClearAllNodes(TrieNode* node);
    bool isLeaf(TrieNode* node);
    bool LetterExists(const char letter, TrieNode* curTrie);
    void insert(const char*);
    bool search(const char*);
    Trie& operator=(const Trie& other) = delete;
    ~Trie();
};

#define WEEK7_TREE_H

#endif //WEEK7_TREE_H

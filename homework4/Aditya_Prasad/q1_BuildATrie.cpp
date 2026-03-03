// Technique : Trie as a parameter
// insert() - T.C = O(L), M.C = O(L)
// isValidWord() - T.C = O(L), M.C = O(1)
// remove() - T.C = O(L), M.C = O(L)
// where L is the length of the word

#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    struct TrieNode {
        vector<TrieNode*> children;
        bool validWord;

        TrieNode() {
            children.resize(26);
            validWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';

            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->validWord = true;
    }

    bool isValidWord(string word) {
        TrieNode* node = root;

        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';

            if (node->children[idx] == nullptr) {
                return false;
            }

            node = node->children[idx];
        }

        return node->validWord;
    }

    bool remove(string word, int depth, TrieNode* node) {
        if (depth == word.size()) {
            if (node->validWord == false) {
                return false;
            }
            node->validWord = false;
            return isEmpty(node);
        }
        bool shouldDeleteChild =
            remove(word, depth + 1, node->children[word[depth] - 'a']);

        if (shouldDeleteChild == true) {
            delete node->children[word[depth] - 'a'];
            node->children[word[depth] - 'a'] = nullptr;
        }

        return (node->validWord == false) && isEmpty(node);
    }

    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                return false;
            }
        }
        return true;
    }
};

// Time Taken : 40 min
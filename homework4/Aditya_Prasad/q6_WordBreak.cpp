// Technique : DP (Memoization) + Trie as a parameter
// T.C : O(T + n*L)
// M.C : O(T + n) 
// where T is sum of all word lengths, L = max(word[i].size()), n = dict.size()

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie () {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->isEnd = true;
    }

    bool searchWord(string word) {
        TrieNode* node = root;

        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (node->children[index] == nullptr) return false;
            node = node->children[index];
        }

        return node->isEnd;
    }
};
bool canBreak(int index, string& word, vector<string>& dictWords, vector<int>& dp, Trie& trie) {
    if (index == word.size()) return true;

    if (dp[index] != -1) return dp[index];

    TrieNode* node = trie.root;

    for (int i = index; i < word.size(); i++) {
        int pos = word[i] - 'a';

        if (node->children[pos] == nullptr) break;

        node = node->children[pos];

        if (node->isEnd == true) {

            bool restResult = canBreak(i + 1, word, dictWords, dp, trie);

            if (restResult == true) {
                return dp[index] = true;
            }
        }
    }

    return dp[index] = false;
}

bool wordBreak(string word, vector<string>& dictWords) {
    Trie trie;
    for (int i = 0; i < dictWords.size(); i++) {
        trie.insert(dictWords[i]);
    }
    vector<int> dp(word.size() + 1, -1);
    return canBreak(0, word, dictWords, dp, trie);
}

int main() {
    vector<string> dictWords = {"elf", "go", "golf", "man", "manatee", "not", "note", "pig", "quip", "tee", "teen"};

    cout << wordBreak("golfman", dictWords) << endl;
    cout << wordBreak("manateenotelf", dictWords) << endl;
    cout << wordBreak("quipig", dictWords) << endl;

    return 0;

}

// Time Taken : 38 mins
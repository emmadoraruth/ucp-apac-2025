// Technique : Trie as a parameter
// T.C : O(T + N*8^L)
// M.C : O(T + N)
// where T is the sum of all word lengths, L = max(word[i].length()), N = dict.size()

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

    bool search(string word) {
        TrieNode* node = root;

        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (node->children[index] == nullptr) return false;
            node = node->children[index];
        }

        return node->isEnd;
    } 
};

    void dfs(int x, int y, string& word, TrieNode* node, vector<vector<bool>>& visited, vector<string>& validWords, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        char c = board[x][y];
        int index = c - 'a';

        if (node->children[index] == nullptr) return;

        node = node->children[index];
        word.push_back(c);

        if (word.size() >= 3 && node->isEnd == true) {
            validWords.push_back(word);
            node->isEnd = false;
        }

        vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}, {-1,-1}, {1,1}, {1,-1}, {-1, 1}};
        
        visited[x][y] = true;

        for (auto [dx, dy] : dir) {
            int newx = x + dx;
            int newy = y + dy;

            if (newx < 0 || newx >= m || newy < 0 || newy >= n || visited[newx][newy] == true) continue;

            dfs(newx, newy, word, node, visited, validWords, board);
        }

        visited[x][y] = false;
        word.pop_back();

    }
    vector<string> findValidWords(unordered_set<string>& words, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        Trie trie;

        vector<string> validWords;

        for (auto word : words) {
            trie.insert(word);
        }
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)  {
                string word;
                dfs(i, j, word, trie.root, visited, validWords, board);
            }
        }

        return validWords;
    }

int main() {
    unordered_set<string> words = {"ace", "ape", "cape", "clap", "clay", "gape", "grape", "lace", "lap", "lay", "mace", "map", "may", "pace", "pay", "race", "rap", "ray", "tap", "tape", "trace", "trap", "tray", "yap"};
    vector<vector<char>> board = {{'a', 'd', 'e'}, {'r', 'c', 'p'}, {'l', 'a', 'y'}};

    vector<string> validWords = findValidWords(words, board);

    for (string validWord : validWords) {
        cout << validWord << " ";
    }

    return 0;

}

// Time Taken : 40 mins
// Technique - Trie + Backtracking (DFS)
// TIME COMPLEXITY - O(KL + M.N.8^L)
// SPACE COMPLEXITY - O(KL)
// where K is number of words in dictionary, L is length of word, M is number of rows and N is number of columns in boards

// assumption - only lowercase letters are present

package homework4.Satyam_Mishra;

import java.util.ArrayList;
import java.util.List;

public class Q2_Boggle {
    static class Trie {
        Trie[] children;
        boolean validWord;

        public Trie() {
            children = new Trie[26];
            validWord = false;
        }
    }

    public static void insert(String word, Trie curr) {
        int n = word.length();

        for(int i = 0; i < n; i++) {
            int ch = word.charAt(i) - 'a';

            if(curr.children[ch] == null) {
                curr.children[ch] = new Trie();
            }
            curr = curr.children[ch];
        }

        curr.validWord = true;
    }

    static int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    public static List<String> findValidWords(char[][] board, String[] dictionary) {
        Trie root = new Trie();
        for(String word : dictionary) {
            insert(word, root);
        }

        List<String> res = new ArrayList<>();

        int m = board.length;
        int n = board[0].length;

        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j];
                if (root.children[ch - 'a'] != null) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(ch);
                    board[i][j] = '0'; // marked as visited node
                    
                    helper(i, j, board, root.children[ch - 'a'], sb, res, root);
                    
                    board[i][j] = ch; // Backtrack
                }
            }
        }

        return res;
    }

    private static void helper(int row, int col, char[][] board, Trie currNode, StringBuilder currWord, List<String> res, Trie root) {
        if(currNode.validWord && currWord.length() >= 3) {
            res.add(currWord.toString());
            remove(0, currWord.toString(), root);
        }

        for(int[] dir : dirs) {
            int adjRow = row + dir[0];
            int adjCol = col + dir[1];
            if(adjRow < 0 ||adjRow >= board.length || adjCol < 0 || adjCol >= board[0].length) continue;

            if(board[adjRow][adjCol] == '0') continue;

            char ch = board[adjRow][adjCol];
            if(currNode.children[ch - 'a'] == null) continue;

            currWord.append(board[adjRow][adjCol]);
            board[adjRow][adjCol] = '0';

            helper(adjRow, adjCol, board, currNode.children[ch - 'a'], currWord, res, root);

            currWord.deleteCharAt(currWord.length() - 1);
            board[adjRow][adjCol] = ch;
        }
    }

    private static boolean remove(int depth, String word, Trie curr) {
        if(curr == null) {
            return false;
        }

        if(depth == word.length()) {
            curr.validWord = false;
            return isEmpty(curr);
        }

        int ch = word.charAt(depth) - 'a';
        boolean shouldDeleteChild = remove(depth + 1, word, curr.children[ch]);

        if(shouldDeleteChild) {
            curr.children[ch] = null;
        } else {
            return false;
        }

        return !curr.validWord && isEmpty(curr);
    }

    private static boolean isEmpty(Trie curr) {
        for(int i = 0; i < 26; i++) {
            if(curr.children[i] != null) return false;
        }

        return true;
    }

    public static void main(String[] args) {
        String[] dictionary = {"ace", "ape", "cape", "clap", "clay", "gape", "grape", "lace", "lap", "lay", "mace", "map", "may", "pace", "pay", "race", "rap", "ray", "tap", "tape", "trace", "trap", "tray", "yap"};
        
        char[][] board = {{'a', 'd', 'e'}, {'r', 'c', 'p'}, {'l', 'a', 'y'}};

        List<String> res = findValidWords(board, dictionary);

        System.out.println(res);
    }
}

// time taken - 30m
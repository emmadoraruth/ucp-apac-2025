// Technique - TRIE + MEMOIZATION
// TIME COMPLEXITY - O(N^2 + WL)
// SPACE COMPLEXITY - O(N^2 + WL)
// where N is length of string, W is number of words in dictionary, L is length of word

package homework4.Satyam_Mishra;

import java.util.HashMap;
import java.util.Map;

public class Q6_WordBreak {
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

    public static boolean canBreak(String word, Trie root, Map<String, Boolean> visited) {
        Trie currNode = root;

        if(word.length() == 0) {
            visited.put(word, true);
            return true;
        }

        if (visited.containsKey(word)) {
            return visited.get(word);
        }

        int n = word.length();

        for(int i = 0; i < n; i++) {
            int ch = word.charAt(i) - 'a';

            if(currNode.children[ch] == null) {
                break;
            }

            currNode = currNode.children[ch];

            if(currNode.validWord) {
                if(canBreak(word.substring(i + 1), root, visited)) {
                    visited.put(word, true);
                    return true;
                }
            }
        }

        visited.put(word, false);
        return false;
    }

    public static void main(String[] args) {
        Trie root = new Trie();

        String[] dictionary = {"elf", "go", "golf", "man", "manatee", "not", "note", "pig", "quip", "tee", "teen"};

        for(String word : dictionary) {
            insert(word, root);
        }
        
        Map<String, Boolean> visited = new HashMap<>();
        System.out.println(canBreak("mangolf", root, visited));
        System.out.println(canBreak("manateenotelf", root, visited));
        System.out.println(canBreak("quipig", root, visited));
    }
}

// time taken - 35m
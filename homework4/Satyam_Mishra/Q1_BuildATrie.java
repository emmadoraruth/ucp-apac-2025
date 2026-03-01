package homework4.Satyam_Mishra;

public class Q1_BuildATrie {
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

    public static boolean isValidWord(String word, Trie curr) {
        int n = word.length();

        for(int i = 0; i < n; i++) {
            int ch = word.charAt(i) - 'a';

            if(curr.children[ch] == null) return false;

            curr = curr.children[ch];
        }

        return curr.validWord;
    }

    public static boolean remove(int depth, String word, Trie curr) {
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
}

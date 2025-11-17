// TC: O(n)
// SC: O(1)
// Category - HASHING
// 29m 15s

package Satyam_Mishra;

import java.util.HashMap;
import java.util.Map;

public class q7_KAnagrams {
    private static boolean checkAnagram(String word1, String word2, int k) {
        int m = word1.length(), n = word2.length();
        if(m != n) return false;

        Map<Character, Integer> freqOfCharInWord1 = new HashMap<>();
        Map<Character, Integer> freqOfCharInWord2 = new HashMap<>();

        for(int i = 0; i < n; i++) {
            char ch1 = word1.charAt(i);
            char ch2 = word2.charAt(i);

            freqOfCharInWord1.put(ch1, freqOfCharInWord1.getOrDefault(ch1, 0) + 1);
            freqOfCharInWord2.put(ch2, freqOfCharInWord2.getOrDefault(ch2, 0) + 1);
        }

        int minChanges = 0;
        for(char key : freqOfCharInWord1.keySet()) {
            int freq1 = freqOfCharInWord1.get(key);
            int freq2 = freqOfCharInWord2.getOrDefault(key, 0);

            if(!freqOfCharInWord2.containsKey(key) || freq1 > freq2) {
                minChanges += freq1 - freq2;
                if(minChanges > k) return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        // Test Case 1
        String word1 = "apple", word2 = "peach";
        int k1 = 1;
        System.out.println("word1 and word2 are k-anagrams: " + checkAnagram(word1, word2, k1));

        // Test Case 2
        String word3 = "apple", word4 = "peach";
        int k2 = 2;
        System.out.println("word3 and word4 are k-anagrams: " + checkAnagram(word3, word4, k2));

        // Test Case 3
        String word5 = "cat", word6 = "dog";
        int k3 = 3;
        System.out.println("word5 and word6 are k-anagrams: " + checkAnagram(word5, word6, k3));

        // Test Case 4
        String word7 = "debit curd", word8 = "bad credit";
        int k4 = 1;
        System.out.println("word7 and word8 are k-anagrams: " + checkAnagram(word7, word8, k4));

        // Test Case 5
        String word9 = "baseball", word10 = "basketball";
        int k5 = 2;
        System.out.println("word9 and word10 are k-anagrams: " + checkAnagram(word9, word10, k5));
    }
}
// TC: O(n)
// SC: O(1)
// Category - TWO POINTERS
// 39m 46s

package Satyam_Mishra;

public class q5_ShortestSubstring {
    private static int shortestString(String str, String required) {
        int n = str.length(), m = required.length();

        int[] req = new int[26];
        for (int i = 0; i < m; i++) {
            req[required.charAt(i) - 'a']++;
        }

        int ans = Integer.MAX_VALUE;
        int[] freq = new int[26];
        int i = 0;

        for (int j = 0; j < n; j++) {
            freq[str.charAt(j) - 'a']++;

            boolean areAllCharacters = true;
            while (areAllCharacters) {
                for (int k = 0; k < 26; k++) {
                    if (freq[k] < req[k]) {
                        areAllCharacters = false;
                        break;
                    }
                }

                if (areAllCharacters) {
                    ans = Math.min(ans, j - i + 1);
                    freq[str.charAt(i) - 'a']--;
                    i++;
                }
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans; // return -1 if not possible
    }

    public static void main(String[] args) {
        // Test Case 1
        String word1 = "abracadabra", required1 = "abc";
        System.out.println("Length of shortest substring containing all characters: " + shortestString(word1, required1));

        // Test Case 2
        String word2 = "zxycbaabcdwxyzzxwdcbxyzabccbazyx", required2 = "zzyzx";
        System.out.println("Length of shortest substring containing all characters: " + shortestString(word2, required2));

        // Test Case 3
        String word3 = "dog", required3 = "god";
        System.out.println("Length of shortest substring containing all characters: " + shortestString(word3, required3));
    }
}

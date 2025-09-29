// TC: O(n)
// SC: O(n)
// Category - STRING MANIPULATION
// 20m 20s

package Satyam_Mishra;
import java.util.List;
import java.util.Set;
import java.util.ArrayList;
import java.util.HashSet;

public class q2_ReverseVowels {
    private static String revVowels(String str) {
        int n = str.length();
        StringBuilder sb = new StringBuilder(str);

        List<Character> vowelsInSequence = new ArrayList<>();
        Set<Character> vowels = new HashSet<>();
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');
        vowels.add('A');
        vowels.add('E');
        vowels.add('I');
        vowels.add('O');
        vowels.add('U');
        for(int i = 0; i < n; i++) {
            char ch = sb.charAt(i);
            if(vowels.contains(ch)) {
                vowelsInSequence.add(ch);
            }
        }

        int ptr = vowelsInSequence.size() - 1;
        for(int i = 0; i < n; i++) {
            char ch = sb.charAt(i);
            if(vowels.contains(ch)) {
                sb.setCharAt(i, vowelsInSequence.get(ptr));
                ptr--;
            }
        }

        return sb.toString();
    }
    public static void main(String[] args) {
        // Test Case 1
        String str1 = "Uber Career Prep";
        System.out.println("str1 after reversing the order of vowels is: " + revVowels(str1));

        // Test Case 2
        String str2 = "xyz";
        System.out.println("str2 after reversing the order of vowels is: " + revVowels(str2));

        // Test Case 3
        String str3 = "flamingo";
        System.out.println("str3 after reversing the order of vowels is: " + revVowels(str3));
    }
}

// TC: O(n^2)
// SC: O(1)
// Category - STRING MANIPULATION
// 17m 22s

// assumed there exist a character before #

package Satyam_Mishra;

public class q4_BackspaceStringCompare {
    private static boolean isSame(String str1, String str2) {
        StringBuilder sb1 = new StringBuilder(str1);
        StringBuilder sb2 = new StringBuilder(str2);

        int i = 0;
        while (i < sb1.length()) {
            char ch = sb1.charAt(i);
            if(ch == '#') {
                sb1.deleteCharAt(i);
                sb1.deleteCharAt(i - 1);
                i -= 2;
            }
            i++;
        }

        i = 0;
        while (i < sb2.length()) {
            char ch = sb2.charAt(i);
            if(ch == '#') {
                sb2.deleteCharAt(i);
                sb2.deleteCharAt(i - 1);
                i -= 2;
            }
            i++;
        }

        return sb1.toString().equals(sb2.toString());
    }
    public static void main(String[] args) {
        // Test Case 1
        String str1 = "abcde", str2 = "abcde";
        System.out.println("str1 is same as str2: " + isSame(str1, str2));
        
        // Test Case 2
        String str3 = "Uber Career Prep", str4 = "u#Uber Careee#r Prep";
        System.out.println("str3 is same as str4: " + isSame(str3, str4));

        // Test Case 3
        String str5 = "abcdef###xyz", str6 = "abcw#xyz";
        System.out.println("str5 is same as str6: " + isSame(str5, str6));

        // Test Case 4
        String str7 = "abcdef###xyz", str8 = "abcdefxyz###";
        System.out.println("str7 is same as str8: " + isSame(str7, str8));
    }
}

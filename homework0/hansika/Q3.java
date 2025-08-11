/*
 * Time: O(n) 
 * Space: O(n)
 */

import java.util.HashSet;
import java.util.Set;

public class Q3
 {
    private static String firstOccurence(String str) 
    {
        Set<Character> again = new HashSet<>(); 

        StringBuilder ans = new StringBuilder();
        for (char ch : str.toCharArray()) {
            if (!again.contains(ch)) {
                ans.append(ch); 
            }
            again.add(ch);
        }

        return ans.toString();
    } 

    public static void main(String[] args) {
        String str1 = "abracadabra";
        String str2 = "Uber Career Prep";
        String str3 = "zzyzx";

        System.out.println("first occuranvce string 1:" + firstOccurence(str1));
        System.out.println("first occurence string 2:" + firstOccurence(str2));
        System.out.println("first occurence string 3:" + firstOccurence(str3));
    }
}
//15 min
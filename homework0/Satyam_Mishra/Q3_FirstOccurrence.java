/*
    Time complexity - O(n) (for traversing the string)
                      O(n) (for converting stringbuilder into string)
                      Overall O(n)

    Space complexity - O(n) (for building ans Stringbuilder) + 
                       O(n) (for adding elements in set in worst case) + 
                       O(n) (for converting it into String in worst case)
                       Overall O(n) in worst case
 */

import java.util.HashSet;
import java.util.Set;

public class Q3_FirstOccurrence {
    private static String firstOccurence(String str) {
        Set<Character> occurence = new HashSet<>(); // set to store unique elements

        StringBuilder ans = new StringBuilder();
        for (char ch : str.toCharArray()) {
            if (!occurence.contains(ch)) {
                ans.append(ch); // if the element wasn't seen before then add it to the ans
            }
            occurence.add(ch);
        }

        return ans.toString();
    } 

    public static void main(String[] args) {
        String str1 = "abracadabra";
        String str2 = "Uber Career Prep";
        String str3 = "zzyzx";

        System.out.println("String with only first occurence in str1 is: " + firstOccurence(str1));
        System.out.println("String with only first occurence in str2 is: " + firstOccurence(str2));
        System.out.println("String with only first occurence in str3 is: " + firstOccurence(str3));
    }
}

// Time taken: 8m 11s
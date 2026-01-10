// Assumptions
// 1. only single space is in between

// DS/Algo used - TRAVERSAL

// Time Complexity = O(N), where R is length of road array
// Space Complexity = O(N)

package homework3.Satyam_Mishra;

public class Q7_ReverseWords {
    private static String reverseWords(String words) {

        String[] wordsArray = words.split(" ");

        StringBuilder sb = new StringBuilder();
        for(int i = wordsArray.length - 1; i >= 0; i--) {
            sb.append(wordsArray[i]);
            if (i > 0) {
                sb.append(" ");
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        String words1 = "Uber Career Prep";
        System.out.println("Reversed words1 is: " + reverseWords(words1));

        String words2 = "Emma lives in Brooklyn, New York";
        System.out.println("Reversed words2 is: " + reverseWords(words2));
    }
}

// time taken 8m 20s
/*
data structure: Stack
algorithm: Push words into a stack and pop them to reverse order
time taken: 10 minutes
time complexity: O(n)
space complexity: O(n)
*/

import java.util.*;
public class ques7
{
    public static String reverseWords(String s)
    {
        if (s == null || s.length() == 0)
        {
            return s;
        }
        String[] words = s.split(" ");
        Stack<String> stack = new Stack<>();
        for (String word : words) // push all words into stack
        {
            stack.push(word);
        }
        StringBuilder result = new StringBuilder();
        while (!stack.isEmpty()) // pop words to reverse order
        {
            result.append(stack.pop());
            if (!stack.isEmpty())
            {
                result.append(" ");
            }
        }
        return result.toString();
    }
    public static void main(String[] args)
    {

        String input1 = "Uber Career Prep";
        String input2 = "Emma lives in Brooklyn, New York.";
        System.out.println("Input: " + input1);
        System.out.println("Output: " + reverseWords(input1));
        System.out.println();
        System.out.println("Input: " + input2);
        System.out.println("Output: " + reverseWords(input2));
    }
}



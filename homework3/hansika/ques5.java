/*
Data structure: Queue
algorithm: BFS
time taken :10 minutes
time complexity: O(k)
space complexity: O(k)
*/

import java.util.*;
public class ques5
{
    public static List<String> firstKBinaryNumbers(int k)
    {
        List<String> result = new ArrayList<>();
        if (k <= 0)
        {
            return result;
        }
        result.add("0");
        if (k == 1)
        {
            return result;
        }
        Queue<String> queue = new LinkedList<>();
        queue.add("1");
        while (result.size() < k)
        {
            String curr = queue.poll();
            result.add(curr);
            queue.add(curr + "0");// Generate next binary numbers
            queue.add(curr + "1");
        }

        return result;
    }
    public static void main(String[] args)
    {

        int k1 = 5;
        int k2 = 10;
        System.out.println("Input: " + k1);
        System.out.println("Output: " + firstKBinaryNumbers(k1));
        System.out.println();
        System.out.println("Input: " + k2);
        System.out.println("Output: " + firstKBinaryNumbers(k2));
    }
}


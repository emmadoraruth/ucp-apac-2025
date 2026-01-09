// DS/Algo used - BFS

// Time Complexity = O(k)
// Space Complexity = O(k)

package homework3.Satyam_Mishra;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class Q5_FirstKBinaryNumbers {
    private static List<String> bfs(int k) {
        List<String> res = new ArrayList<>();
        if(k == 0) return res;

        res.add("0");
        if(k == 1) return res;

        Queue<String> q = new ArrayDeque<>();
        q.add("1");
        res.add("1");

        while(res.size() < k) {
            String front = q.poll();
            
            String addZero = front + "0";
            String addOne = front + "1";

            q.add(addZero);
            res.add(addZero);

            if(res.size() < k) {
                q.add(addOne);
                res.add(addOne);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int k1 = 5;
        List<String> res1 = bfs(k1);
        System.out.println("First k1 binary numbers are: " + res1);

        int k2 = 10;
        List<String> res2 = bfs(k2);
        System.out.println("First k2 binary numbers are: " + res2);
    }
}

// time taken 20m 15s

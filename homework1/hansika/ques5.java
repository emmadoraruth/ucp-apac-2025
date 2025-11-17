
// Technique: Variable-size Sliding Window + Hashing (frequency counts)
// Time Complexity: O(n)
// Space Complexity: O(k)

import java.util.HashMap;
public class ques5
{

    public static int shortestSubstring(String s, String required) 
    {
        if (s == null || required == null || required.length() == 0) 
        {
            return 0;
        }

        // Count required characters
        HashMap<Character, Integer> need = new HashMap<>();
        for (char c : required.toCharArray()) 
        {
            need.put(c, need.getOrDefault(c, 0) + 1);
        }

        int requiredUnique = need.size();
        int formed = 0;

        HashMap<Character, Integer> windowCounts = new HashMap<>();
        int left = 0, minLen = Integer.MAX_VALUE;

        for (int right = 0; right < s.length(); right++) 
        {
            char c = s.charAt(right);
            windowCounts.put(c, windowCounts.getOrDefault(c, 0) + 1);
            if (need.containsKey(c) && windowCounts.get(c).intValue() == need.get(c).intValue()) 
            {
                formed++;
            }
            while (left <= right && formed == requiredUnique)
             {
                int windowLen = right - left + 1;
                if (windowLen < minLen) 
                {
                    minLen = windowLen;
                }

                char leftChar = s.charAt(left);
                windowCounts.put(leftChar, windowCounts.get(leftChar) - 1);
                if (need.containsKey(leftChar) && windowCounts.get(leftChar) < need.get(leftChar)) 
                {
                    formed--;
                }
                left++;
            }
        }

        return (minLen == Integer.MAX_VALUE) ? 0 : minLen;
    }

    public static void main(String[] args) {
        // Test Cases
        System.out.println(shortestSubstring("abracadabra", "abc")); // Expected: 4 ("brac")
        System.out.println(shortestSubstring("zxycbaabcdwxyzzxwdcbxyzabccbazyx", "zzyzx")); // Expected: 10 ("zzxwdcbxyz")
        System.out.println(shortestSubstring("dog", "god")); // Expected: 3 ("dog")        
    }
}

// Time spent: ~30 minutes

// Technique: Hashing (frequency counts)
// Time Complexity: O(n)
// Space Complexity: O(1)
public class ques7 
{
    public static boolean areKAnagrams(String s1, String s2, int k) 
    {
        if (s1.length() != s2.length()) 
        {
            return false;
        }
         //Count frequencies in s1
        int[] freq = new int[26];
        for (char c : s1.toCharArray())
         {
            if (Character.isLetter(c))
             {
                freq[Character.toLowerCase(c) - 'a']++;
            }
        }

        //Reduce counts using s2
        for (char c : s2.toCharArray()) 
        {
            if (Character.isLetter(c)) 
            {
                freq[Character.toLowerCase(c) - 'a']--;
            }
        }

        //Count how many extra chars are in s1
        int changesNeeded = 0;
        for (int val : freq) 
        {
            if (val > 0) 
            {
                changesNeeded += val;
            }
        }
        return changesNeeded <= k;
    }

    public static void main(String[] args) 
    {
        // Test Cases
        System.out.println(areKAnagrams("apple", "peach", 1));  // False
        System.out.println(areKAnagrams("apple", "peach", 2));  // True
        System.out.println(areKAnagrams("cat", "dog", 3));      // True
        System.out.println(areKAnagrams("debit curd", "bad credit", 1)); // True
        System.out.println(areKAnagrams("baseball", "basketball", 2));   // False
    }

}
// time: 12 min
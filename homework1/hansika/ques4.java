// Technique: Forward/backward two-pointer
// Time Complexity: O(n + m)
//Space Complexity: O(1)

public class ques4 
{

    // find next valid character index going backwards
    private static int getNextValidCharIndex(String s, int index)
     {
        int backspaceCount = 0;
        while (index >= 0) {
            if (s.charAt(index) == '#')
             {
                backspaceCount++;
                index--;
            } 
            else if (backspaceCount > 0)
             {
                backspaceCount--;
                index--;
            } else
             {
                break;
            }
        }
        return index;
    }

    public static boolean backspaceCompare(String s1, String s2) {
        int i = s1.length() - 1;
        int j = s2.length() - 1;

        while (i >= 0 || j >= 0) {
            i = getNextValidCharIndex(s1, i);
            j = getNextValidCharIndex(s2, j);

            // Compare characters
            if (i >= 0 && j >= 0) 
            {
                if (s1.charAt(i) != s2.charAt(j)) return false;
            } else
             {
                if (i >= 0 || j >= 0) return false;
            }

            i--;
            j--;
        }

        return true;
    }

    public static void main(String[] args) {
        System.out.println(backspaceCompare("abcde", "abcde")); // true
        System.out.println(backspaceCompare("Uber Career Prep", "u#Uber Careee#r Prep")); // true
        System.out.println(backspaceCompare("abcdef###xyz", "abcw#xyz")); // true
        System.out.println(backspaceCompare("abcdef###xyz", "abcdefxyz###")); // false
    }
}

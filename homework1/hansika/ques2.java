// Technique: Two-Pointer
// Time Complexity: O(n)
// Space Complexity: O(n)

public class ques2 
{

    public static String reverseVowels(String s) 
    {
        if (s == null || s.length() == 0) 
        {
            return s;
        }
        char[] arr = s.toCharArray();
        int left = 0, right = arr.length - 1;

        while (left < right) 
        {
            // Move left pointer until vowel
            while (left < right && !isVowel(arr[left])) 
            {
                left++;
            }
            // Move right pointer until vowel
            while (left < right && !isVowel(arr[right])) 
            {
                right--;
            }
            // Swap vowels
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }

        return new String(arr);
    }

    private static boolean isVowel(char c) 
    {
        c = Character.toLowerCase(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    public static void main(String[] args) {
        // Test Cases
        System.out.println(reverseVowels("Uber Career Prep")); // Expected: eber Ceraer PrUp
        System.out.println(reverseVowels("xyz"));              // Expected: xyz
        System.out.println(reverseVowels("flamingo"));         // Expected: flominga
    }
}

// Time spent: ~15 minutes

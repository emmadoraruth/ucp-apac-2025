#include <bits/stdc++.h>
using namespace std;
 // It took me around 30 minutes to compelete
 //as i tried to use an unordered map to solve, then got an complexity of O(n^2)
 // and then moved to another method , two pointer approach
 //time  -> O(n) and space -> constant ->O(1)
int vowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' )
    {
        return 1;
    }else
    {
        return 0;
    }
}

int main()
{
    string s;
    getline (cin,s);
    int p = s.size();

    int right = p-1;
    int left = 0;

    while(left < right)
    {
        int l = vowel(s[left]);
        int r = vowel(s[right]);

        if(l == 0)
        {
            left ++;
        }elseif(r==0)
        {
            right --;
        }else
        (left < right && l == 1 && r == 1)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }

    }

    cout << s <<endl;

    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//I used stack and traversal in it, It took me around 20 minutes to finish
// Time complexity: O(n)
//Sapce complexity: O(n)

string reversewords(string s) 
{
    stack<string> st;
    string word = "";
    for (int i = 0; i < (int)s.size(); i++) 
    {
        if (s[i] == ' ') 
        {
            if (!word.empty()) 
            {
                st.push(word);
                word = "";
            }
        } else 
        {
            word += s[i];
        }
    }

    if (!word.empty()) 
    {
        st.push(word);
    }

    string result = "";
    while (!st.empty()) 
    {
        result += st.top();
        st.pop();
        if (!st.empty()) result += " ";
    }

    return result;
}


int main() {
    string s1 = "Uber Career Prep";
    string s2 = "Emma lives in Brooklyn, New York.";

    cout << reversewords(s1) << endl;
    cout << reversewords(s2) << endl;
    return 0;
}

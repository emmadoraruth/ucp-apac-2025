// Question 2 : Reverse vowels
// Time Complexity : O(n)    Space Complexity: O(n)     Time Taken: 21 minutes 1 second

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ReverseVowels (string& s){
    
    vector<char> vowels;
    vector<int> indices;
    
    for(int i = 0;i<s.size();i++){
     if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U') {
        indices.push_back(i);
        vowels.push_back(s[i]);
     }
    }

    for(int i = 0;i<vowels.size();i++){
        s[indices[i]] = vowels[vowels.size()-1-i];
    }

    return s;
}

int main() {
    
    string str1 = "Uber Career Prep";
    cout << ReverseVowels(str1) << endl; 
    
    string str2 = "xyz";
    cout << ReverseVowels(str2) << endl; 
    
    string str3 = "flamingo";
    cout << ReverseVowels(str3) << endl; 
    
    string str4 = "Yash";
    cout << ReverseVowels(str4) << endl;

    string str5 = "";
    cout << ReverseVowels(str5) << endl;

    return 0;
}
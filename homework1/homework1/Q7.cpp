// Question 7 : K-Anagrams
// Time Complexity: O(n)   Space Complexity: O(m)   Time Taken: 36 minutes 43 seconds

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool KAnagrams(string s1, string s2, int k){
    if(s1.size() != s2.size()){
        return false; 
    }

    unordered_map<char,int> freq1;
    unordered_map<char,int> freq2;

    for(char c : s1){
        if(c != ' ') freq1[c]++;
    }
    for(char c : s2){
        if(c != ' ') freq2[c]++;
    }

    int changes_needed = 0;

    for(auto it : freq1){
        char c = it.first;
        int count1 = it.second;
        int count2 = freq2[c];

        if(count1 > count2){
            changes_needed += (count1 - count2);
        }
    }

    if(changes_needed <= k){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s1 = "apple";
    string s2 = "peach";
    cout << (KAnagrams(s1, s2, 1) ? "True" : "False") << endl; 
    cout << (KAnagrams(s1, s2, 2) ? "True" : "False") << endl; 

    string s3 = "cat";
    string s4 = "dog";
    cout << (KAnagrams(s3, s4, 3) ? "True" : "False") << endl; 

    string s5 = "debit curd";
    string s6 = "bad credit";
    cout << (KAnagrams(s5, s6, 1) ? "True" : "False") << endl; 

    string s7 = "baseball";
    string s8 = "basketball";
    cout << (KAnagrams(s7, s8, 2) ? "True" : "False") << endl; 

    return 0;
}

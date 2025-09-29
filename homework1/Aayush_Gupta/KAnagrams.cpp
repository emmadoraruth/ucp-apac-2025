#include<bits/stdc++.h>
using namespace std;
//TC: O(n)
//SC: O(1) as there are maximum 26 alphabets that makes it a deterministic value 
bool checkKAnagrams(string text1, string text2,int k){
       if(text1.length()!=text2.length()) return false;
       unordered_map<char,int>charFreqMap;
       for(int i=0;i<text1.length();i++){
           charFreqMap[text1[i]]++;
       }
       for(int i=0;i<text2.length();i++){
           char character=text2[i];
           if(charFreqMap[character]>0){
               charFreqMap[character]--;
           }
       }
       int count=0;
    for (pair<char,int>p:charFreqMap) {
        count +=p.second;
    }

    if (count > k) {
        return false;
    }
    return true;
}




int main(){
    string s1, s2;
    int k;
    cin >> s1 >> s2 >> k;
    
    if (checkKAnagrams(s1, s2, k))
        cout << "True";
    else
        cout << "False";
    
    
    return 0;
}
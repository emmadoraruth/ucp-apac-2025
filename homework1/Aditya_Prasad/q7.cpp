// N = string length
// T.C = O(3N) = O(N)
// M.C = O(N) because of the unordered_map
// Hashing Technique : Two arrays/strings increment/decrement hashmap counts
// Time Taken : 40 min 


#include <bits/stdc++.h>
using namespace std;

bool checkKAnagrams(string word1, string word2, int k){
    if(word1.length() != word2.length()) return false;
    
    unordered_map<char,int> freqMap; 
    
    for(int i=0;i<word1.length();i++){
        freqMap[word1[i]]++; // O(N)
        
    }
    
    for(int i=0;i<word2.length();i++){
        freqMap[word2[i]]--; // O(N)
    }
    
    int noOfCharChange = 0;
    
    for(auto element : freqMap){ // O(N) in worst case
        if(element.second > 0) noOfCharChange += element.second;
    }
    
    if(noOfCharChange > k) return false;
    
    return true;
    
}

int main() {
    
    cout << checkKAnagrams("apple","peach",1) << endl;
    cout << checkKAnagrams("apple","peach",2) << endl;
    cout << checkKAnagrams("cat","dog",3) << endl;
    cout << checkKAnagrams("debit curd","bad credit",1) << endl;
    cout << checkKAnagrams("baseball","basketball",2) << endl;

}

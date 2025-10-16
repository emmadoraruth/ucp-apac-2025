#include <bits/stdc++.h>
using namespace std;

bool kana(string str1, string str2, int k){
    vector<int> count(26, 0);
    for(char c: str1){
        count[c - 'a']++;
    }
    for(char c: str2){
        count[c - 'a']--;
    }
    int diff = 0;
    int diff2 = 0;
    for(int c: count){
        if(c > 0) diff += c;
        if(c < 0) diff2 += c;
    }

    if(diff != -diff2) return false;
    return diff <= k;
}

int main(){
    string str1 = "apple";
    string str2 = "peach";
    int k = 1;
    cout << boolalpha << kana(str1, str2, k) << "\n"; // Output: true

    str1 = "apple";
    str2 = "peach";
    k = 2;
    cout << boolalpha << kana(str1, str2, k) << "\n"; // Output: false

    str1 = "cat";
    str2 = "dog";
    k = 3;
    cout << boolalpha << kana(str1, str2, k) << "\n"; // Output: false
}
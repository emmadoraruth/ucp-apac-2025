// Given a string, return a string that contains only the first occurrence of each character in the string.

// Examples:
// Input String: "abracadabra"
// Output: "abrcd"

// Input String: "Uber Career Prep"
// Output: "Uber CaPp"

// Input String: "zzyzx"
// Output: "zyx"


//Time complexity: O(n)
//space complexity: O(k)
#include<iostream>
#include<unordered_map>
using namespace std;
string firstocc(string str){
    unordered_map<char,int> cnt;
    string ans="";
    for(auto& ch:str){
        if(cnt.count(ch) == 0){
            ans.push_back(ch);
            cnt[ch]++;
        }
    }
    return ans;
}
int main(){
    string s1="abracadabra";
    string s2="Uber Career Prep";
    string s3="zzyzx";

    cout<<"  1)  "<<firstocc(s1)<<endl;
    cout<<"  2)  "<<firstocc(s2)<<endl;
    cout<<"  3)  "<<firstocc(s3)<<endl;
}
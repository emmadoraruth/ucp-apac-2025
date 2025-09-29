// Two strings are considered to be “k-anagrams” if they can be made into anagrams 
//by changing at most k characters in one of the strings. Given two strings and an
// integer k, determine if they are k-anagrams.

// Examples:
// Input Strings: "apple", "peach"
// Input k: 1
// Output: False

// Input Strings: "apple", "peach"
// Input k: 2
// Output: True

// Input Strings: "cat", "dog"
// Input k: 3
// Output: True

// Input Strings: "debit curd", "bad credit"
// Input k: 1
// Output: True

// Input Strings: "baseball", "basketball"
// Input k: 2
// Output: False

//***********************************************88 */
//time taken:11 min
//Time complexity:O(n)
//space complexity:O(N)
#include<bits/stdc++.h>
using namespace std;
bool isanagram(string s1,string s2,int k){
    if(s1.size()!=s2.size()) return false;
    unordered_map<char,int> cnt;
    for(auto& i:s1)
       cnt[i]++;
    int diff=0;
    for(auto& i:s2){
        if(cnt.find(i)==cnt.end()){
            diff++;
        }
        else if(cnt[i]>0){
            cnt[i]--;
        }
    }
    for(auto& i:cnt){
        if(i.second>0){
            diff+=i.second;
            i.second=0;
        }
    }
    if(diff<=k*2){
        return true;
    }
    return false;
}
int main(){
    string s1_1="apple";
    string s1_2="peach";
    int k1=1;
    bool anag1=isanagram(s1_1,s1_2,k1);

    string s2_1="apple";
    string s2_2="peach";
    int k2=2;
    bool anag2=isanagram(s2_1,s2_2,k2);

    string s3_1="cat";
    string s3_2="dog";
    int k3=3;
    bool anag3=isanagram(s3_1,s3_2,k3);

    string s4_1="debit curd";
    string s4_2="bad credit";
    int k4=2;
    bool anag4=isanagram(s4_1,s4_2,k4);

    string s5_1="baseball";
    string s5_2="basketball";
    int k5=1;
    bool anag5=isanagram(s5_1,s5_2,k5);

    cout<<anag1<<endl;
    cout<<anag2<<endl;
    cout<<anag3<<endl;
    cout<<anag4<<endl;
    cout<<anag5<<endl;
}
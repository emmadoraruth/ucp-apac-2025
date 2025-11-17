/*
Time Complexity: O(s+t)  
Space Complexity: O(t)
*/

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int len(string s,string t ){
    unordered_map<char,int>mpp;  //building requency map for all characters in t
    for(int i=0;i<t.size();i++){
        mpp[t[i]]++;
    }
   int count = 0;          // number of characters matched so far while traversing in my window
    int left = 0;           // left pointer of the window
    int right = 0;          // right pointer of the window
    int minlen = 999999;    // stores minimum window length found
    while(right<s.size()){      // expand the window by moving 'right'
        if(mpp[s[right]]>0){
            count++;          // we have matched one more required character
        }
        mpp[s[right]]--;        // Decrease count of this character (since it's now part of my window)
        while(count==t.size()){
            if(right-left+1<minlen){
                minlen=right-left+1;
            }
             // Shrink the window from left side
            mpp[s[left]]++;  // add back the left character to map
            
            if(mpp[s[left]]>0){
                count--;
            }
            left++;  //moves left pointer forward
        }
        right++;
        
    }
    return minlen;  //return the smallest windows length
}
int main(){
    string  s= "abracadabra";
    string t="abc";
    cout<<len(s,t)<<endl;
    cout<<len( "zxycbaabcdwxyzzxwdcbxyzabccbazyx","zzyzx")<<endl;
    cout<<len("dog","god");

}

#include<bits/stdc++.h>
using namespace std;
//Time complexity: O(n)
//Space complexity: O(n)


string firstOccurence(string str){

    if(str.empty()){
        return str;
    }
    
    unordered_map<char,int>charToIdxMap;
    string result="";
    for(int i=0;i<str.length();i++){
        if(charToIdxMap.find(str[i])!=charToIdxMap.end()){
            continue;
        }
        else{
            charToIdxMap[str[i]]=i;
        }
    }
    
     for(int i=0;i<str.length();i++){
             if(charToIdxMap.find(str[i])!=charToIdxMap.end()){
                result.push_back(str[i]);
                charToIdxMap.erase(str[i]);
             }
     }
     return result;
     
    
}

int main(){
        
   string s;
   getline(cin,s); 

    //Assumptions: The assumption is that the first cocurence will be performed on the entire string 
    //even if it is space separated and not on each sub-string in a string(space separated)
    cout<<firstOccurence(s)<<endl; 


    return 0;
}
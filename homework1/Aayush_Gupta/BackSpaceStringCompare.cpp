#include<bits/stdc++.h>
using namespace std;

//TC:O(n+m) where n amd m are length of strings 
//SC:O(1)
string removeBackSpaces(string &input){
    int index=0;
    for(int i=0;i<input.size();i++){
            if(input [i]!='#'){
              input[index]=input[i];
              index++;
            }
            else if(input[i]=='#' && index>=0){
                 index--;
            }
            if(index<0){
              index=0;
            }
    }
    return input.substr(0,index);
}

void  backSpaceStringCompare(string text1, string text2){
    if(removeBackSpaces(text1)==removeBackSpaces(text2)){
         cout<<"True";
         return;
    }
    cout<<"False";
      
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    backSpaceStringCompare(s1, s2);
    return 0;
    return 0;
}
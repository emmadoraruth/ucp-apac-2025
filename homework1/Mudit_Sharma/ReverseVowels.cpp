// Given a string, reverse the order of the vowels in the string.

// Examples:
// Input String: "Uber Career Prep"
// Modified String: "eber Ceraer PrUp"

// Input String: "xyz"
// Modified String: "xyz"

// Input String: "flamingo"
// Modified String: "flominga"

//2:01 -

//time taken: 10 min
//Time Complexity:O(n)
//Space complexity:O(1)
#include<bits/stdc++.h>
using namespace std;
bool isvow(char ch){
    if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' ||
    ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        return true;
    }
    return false;
}
void rev(string& str){
    int s=0;
    int e=str.size()-1;
    while(s<e){
        if(str[s]==' '){
            s++;
        }
        if(str[e]==' '){
            e--;
        }
        else if(isvow(str[s]) && isvow(str[e])){
            swap(str[s++],str[e--]);
        }
        if(!isvow(str[s])){
            s++;
        }
        if(!isvow(str[e])){
            e--;
        }
    }

}
int main(){
    string s1="Uber Career Prep";
    rev(s1);
    cout<<s1;
}
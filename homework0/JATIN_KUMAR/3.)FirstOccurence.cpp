#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>









// timecomplexity= O(n);
// spaceComplexity= O(n);


string FirstOcc(string str){
    unordered_map<char,int>mp;
    string ans;
    for(int i=0;i< str.length();i++){
        char ch= str[i];
        if(mp[ch]==0){
            ans=ans+ch;
            mp[ch]++;
        }
        

    }
    return ans;

}

int main(){
    string str="abracadabra";
    cout<<FirstOcc(str)<<endl;
}

// time taken = 10 min
#include<iostream>
using namespace std;
#include<vector>

// Generate first k binary numbers
// tc: O(n log n) for converting numbers to binary strings
// sc: O(n) for storing the binary strings
// time taken: 25 min
vector<string> Firstkbinary(int n){
    vector<string> ans;
    if(n==1){
        ans.push_back("0");
        return ans;
    }
    if(n==2){
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }
    ans.push_back("0");
    ans.push_back("1");
    for(int i=0;i<n-2;i++){
        string h="";
        int num=i+2;
        while(num>1){
         int rem=num%2;
           h=to_string(rem)+h;
            num=num/2;
        }
        h="1"+h;    
        ans.push_back(h);
        

    }
    return ans;

    

}

int main() {
        int n;
        cin>>n;
        vector<string> res=Firstkbinary(n);
        for(auto str:res){
            cout<<str<<endl;
        }
    }
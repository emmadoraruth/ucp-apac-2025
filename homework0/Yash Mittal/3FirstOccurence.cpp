// Time Complexity : O(n) 
// Space Complexity : O(n)



#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

string FirstOccurence(string s){
string ans = "";
set<char> set1;

for(char c:s){
    if(set1.count(c)==1){continue;}
    else{
        set1.insert(c);
        ans += c;
    }
}
return ans;
}

int main(){

string testcase1 = "abracadabra";
string testcase2 = "Uber Career Prep";
string testcase3 = "zzyzx";

cout<<"Output for testcase 1: "<<FirstOccurence(testcase1)<<endl;
cout<<"Output for testcase 2: "<<FirstOccurence(testcase2)<<endl;
cout<<"Output for testcase 3: "<<FirstOccurence(testcase3)<<endl;

}
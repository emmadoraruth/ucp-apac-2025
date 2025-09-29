// Question 4: Backspace String Compare
//Time Complexity: O(n)  Space Complexity: O(n)  Time Taken: 22 minutes 15 seconds 

#include <iostream>
#include <string>
using namespace std;


string BackspaceProcessing (string s){
string processed_string = "";

for(char c:s){
    if(c=='#'){
        if(!processed_string.empty()){
            processed_string.pop_back();
        }
        else{
            continue;
        }
    }
    else{
        processed_string.push_back(c);
    }
}

return processed_string;
}

bool Answer(string s1, string s2){
    if(s1==s2){
        return true;
    }
    return false;
}

int main(){
    string s1 = "ab#c";
    string s2 = "ad#c";
    cout << (Answer(BackspaceProcessing(s1), BackspaceProcessing(s2)) ? "True" : "False") << endl;
   
    string s3 = "a#c";
    string s4 = "b";
    cout << (Answer(BackspaceProcessing(s3), BackspaceProcessing(s4)) ? "True" : "False") << endl;
    
    string s5 = "x#";
    string s6 = "";
    cout << (Answer(BackspaceProcessing(s5), BackspaceProcessing(s6)) ? "True" : "False") << endl;
    

    return 0;
}

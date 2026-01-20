// Question 5 : First K Binary Numbers
// Time Taken : 26 minutes

#include <iostream>
#include <vector>
using namespace std;

vector<string> FirstKBinary(int n){
    vector<string> FirstK;
    if(n<=0){
        return FirstK;
    }
    
    FirstK.push_back("0");
    
    if(n==1){
        return FirstK;
    }

    FirstK.push_back("1");

    if(n==2){
        return FirstK;
    }

    int point = 1;

    for(int i = 2;i<n;i++){
         if (i % 2 == 0) {
            FirstK.push_back(FirstK[(i / 2)] + "0");
        } else {
            FirstK.push_back(FirstK[(i / 2)] + "1");
        }
    }

    return FirstK;
}

void Answer(vector<string> arr){
    for(string s : arr){
        cout<<s<<" ";
    }
    cout<<endl;
}

int main(){
    vector<string> testcase1 = FirstKBinary(5);
    vector<string> testcase2 = FirstKBinary(10);
    vector<string> testcase3 = FirstKBinary(1);
    vector<string> testcase4 = FirstKBinary(0);
    vector<string> testcase5 = FirstKBinary(100);

    Answer(testcase1);
    Answer(testcase2);
    Answer(testcase3);
    Answer(testcase4);
    Answer(testcase5);

    return 0;
}
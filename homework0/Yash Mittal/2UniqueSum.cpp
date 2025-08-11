// Time Complexity : O(n)
// Space Complexity : O(n)





#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;



int UniqueSum(vector<int> arr){
    set<int> set1;
    int ans = 0;

    for(int i : arr){
        if(set1.count(i)==1){
            continue;
        }
        else{
            set1.insert(i);
            ans += i;
        }
    }
    return ans;

}

int main(){
vector<int> testcase1 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
vector<int> testcase2 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};

cout<<"Output for testcase1: "<<UniqueSum(testcase1)<<endl;
cout<<"Output for testcase2: "<<UniqueSum(testcase2)<<endl;
}
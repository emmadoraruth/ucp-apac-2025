// Question 3 : Zero Sum Sub Arrays
// Time Complexity : O(n)   Space Complexity:  O(n)       Time Taken: 28 minutes 16 seconds

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int ZeroSumSubArrays (vector<int> arr){
vector<int> prefixsum;
unordered_map<int , int> frequency_prefixsum;
int answer = 0;

if(arr.size()==0){
    cout<<"Input array is empty. (Invalid Input) ";
    return -1;
    cout<<endl;
}

frequency_prefixsum[0]=1;

prefixsum.push_back(arr[0]);

for(int i = 1;i<arr.size();i++){
    prefixsum.push_back(prefixsum.back()+arr[i]);
}

for(int i : prefixsum){
    if(frequency_prefixsum[i]==0){
        frequency_prefixsum[i] = 1;
    }
    else{
        answer += frequency_prefixsum[i];
        frequency_prefixsum[i]++;
    }
}

return answer;


}

int main(){

}
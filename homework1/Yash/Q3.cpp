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
vector<int> arr1 = {1, -1, 2, -2, 3};
    cout << ZeroSumSubArrays(arr1) << endl; 

    vector<int> arr2 = {0, 0, 0};
    cout << ZeroSumSubArrays(arr2) << endl; 

    vector<int> arr3 = {3, 4, -7, 3, 1, 3, -4, -2, -2};
    cout << ZeroSumSubArrays(arr3) << endl; 

    vector<int> arr4 = {};
    cout << ZeroSumSubArrays(arr4) << endl; 

    vector<int> arr5 = {4, 5, 2, -1, -3, -3, 4, 6, -7};
    cout << ZeroSumSubArrays(arr5) << endl; 

    vector<int> arr6 = {1, 8, 7, 3, 11, 9};
    cout << ZeroSumSubArrays(arr6) << endl; 

    vector<int> arr7 = {8, -5, 0, -2, 3, -4};
    cout << ZeroSumSubArrays(arr7) << endl; 

    return 0;
}

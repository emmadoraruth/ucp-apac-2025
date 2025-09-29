// Question 1 : Max Mean Sub Array
// Time Complexity : O(n)  Space Complexity : O(1)    Time Taken : 27 minutes 13 seconds


#include <iostream>
#include <vector>
using namespace std;

bool error_test(int k,int size){
    if(k>size || (k==0 && size ==0) || (k<0 || size<0)){
        return true;
    }
    else{
        return false;
    }
}

double MaxMeanSubArray(vector<int> arr,int k){
int size = arr.size();

if(!(error_test(k,size))){
int left_pointer = 0;
int right_pointer = k-1;
double max_mean = 0;
double value = 0; // value of all the subarrays

for(int i = 0;i<k;i++){
 value += arr[i];
 max_mean += arr[i];
}

for(int i = 0;i<size-k;i++){
    value -= arr[left_pointer++];
    value += arr[++right_pointer];
    max_mean = max(value,max_mean);
}

double ans = max_mean/k;
return (ans);
}
else{
cout<<"The subarray size is greater than the size of the array. (Invalid Input)";
}

return 0;
}

int main(){

    vector<int> arr1 = {4, 5, -3, 2, 6, 2};
    cout << MaxMeanSubArray(arr1, 2) << endl;

    vector<int> arr2 = {4, 5, -3, 2, 6, 1};
    cout << MaxMeanSubArray(arr2, 3) << endl;

    vector<int> arr3 = {1, 1, 1, 1, -1, -1, 2, -1, -1};
    cout << MaxMeanSubArray(arr3, 3) << endl;

    vector<int> arr4 = {1, 1, 1, 1, -1, -1, 2, -1, -1, 6};
    cout << MaxMeanSubArray(arr4, 5) << endl;

    return 0;
}

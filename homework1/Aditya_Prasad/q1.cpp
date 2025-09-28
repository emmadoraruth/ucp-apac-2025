// I've used Fixed-size sliding window
// T.C = O(n)
// M.C = O(n) (for testcases)
// Time Taken = 10 mins

#include <bits/stdc++.h>
using namespace std;

float MaxMeanSubArray(vector<int> arr, int k){
    int n = arr.size();
    int sum = 0;
    
    for(int i=0;i<k;i++){ // intiate window of size k - O(k)
        sum += arr[i];
    }
    
    int maxSum = sum;
    
    for(int i=k;i<n;i++){ // process window - O(n-k)
        sum += arr[i] - arr[i-k];
        maxSum = max(maxSum, sum);
    }
    
    
    return (float)maxSum/k;

}

int main(){
    vector<int> v1 = {4, 5, -3, 2, 6, 1};
    vector<int> v2 = {1, 1, 1, 1, -1, -1, 2, -1, -1};
    vector<int> v3 = {1, 1, 1, 1, -1, -1, 2, -1, -1, 6};
    
    cout << MaxMeanSubArray(v1,2) << endl;
    cout << MaxMeanSubArray(v1,3) << endl;
    cout << MaxMeanSubArray(v2,3) << endl;
    cout << MaxMeanSubArray(v3,5);
    
}

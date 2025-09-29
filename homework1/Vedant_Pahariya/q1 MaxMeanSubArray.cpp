// Problem Statement
/* Given an array of integers and an integer, k, find the maximum mean of a subarray of size k. */

// Technique: Fixed-size Sliding Window
// Time Complexity: O(n), n is the length of the array
// Space Complexity: O(1), just used few variables like sum, maxsum etc.

#include <bits/stdc++.h>
using namespace std;

float meanmaxing(vector<int>& arr, int k){
    // int meanmaxing(int* arr, int k){
    // Googled for sizeof/size function
    /* 
    cout << sizeof(arr)/sizeof(arr[0]); will not work because arr is a pointer here, not an array. it will give 8/4 = 2 (on a 64-bit system) which is not the size of the array. (size of pointer is 8 bytes and size of int is 4 bytes)
    size function will also not work because arr is a pointer here, not an array. size function operates on array.
    */
   long long int sum =0; // long long int is minimum 8 bytes and long int 4 bytes
    // sum of ints can exceed the range of int so taking long long int

    // long long int maxsum = LLONG_MIN; // Because there are negative numbers also in array
    
    for(int i = 0; i< k; i++){
            sum += arr[i];
    }

    long long int maxsum = sum;

    for(int i=k; i< arr.size(); i++){
        sum += arr[i] - arr[i-k];
        maxsum = max(maxsum, sum);
    }
    
    //I am not calculating mean at every step. To calculate mean we have to divide by k which is unnecessary to do after every step because it will generate unnecessary instructions at assembly level to divide after every step. Instead I will just divide maxsum by k at the end and return it. (instruction level optimization)
    
    // I can do the above thing in single for loop but that will introduce a if condition inside the loop which will increase the number of instructions at assembly level. So, I am doing it in two loops to avoid that if condition.

    // Although I agree that this will not make much difference in time complexity but still I feel that it is a good practice to avoid unnecessary operations.

    // return maxsum/k;
    // this will return int because both are int, so typecasting one of them to float
    return (float)maxsum/k;
}

int main(){
    vector <int> arr = {4, 5, -3, 2, 6, 1};
    // cout << size(arr);
    cout << meanmaxing(arr, 2) << "\n";

    arr = {4, 5, -3, 2, 6, 1};
    cout << meanmaxing(arr, 3) << "\n";

    arr = {1, 1, 1, 1, -1, -1, 2, -1, -1};
    cout << meanmaxing(arr, 3) << "\n";

    arr = {1, 1, 1, 1, -1, -1, 2, -1, -1, 6};
    cout << meanmaxing(arr, 5);
}   

// Thinking Process
/* 
1) After reading the question first time, I thought that subarray of k implies any k elements of array. Then after reading the test cases, realized that it is continuous k elements (not any k). Searching more about this in google got to know about following three important terms:
Subarrays: A contiguous block of elements within an array.
Subsequences: A sequence derived from another sequence where some elements may be deleted without changing the order of the remaining elements. For array with n elements, there are (2^n)-1 possible non-empty subsequences.
Subsets: A set formed from a given set by taking some or all elements without regard to the order.

2) After understanding the problem, I thought of brute force approach where I can take all possible subarrays of size k and calculate their means and return the maximum mean. This approach will be O(n*k) time complexity. 

3) Logically, we are taking a window of size k and sliding it through the array. So, lets say I found the mean of first k numbers in array, then to find the mean of next k numbers, I can just subtract the first number of previous k numbers and add the next number in the array. This way I can find the mean of all subarrays of size k in O(n) time complexity.

4) I will maintain a variable to store the maximum mean found so far and update it whenever I find a new mean that is greater than the current maximum mean.
*/
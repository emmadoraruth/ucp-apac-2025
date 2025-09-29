// I've used binary search
// T.C = logn
// M.C = O(1)
// Time Taken = 30 min 


#include <bits/stdc++.h>
using namespace std;

int MissingInteger(vector<int> arr, int n){
    
    int left = 0; int right = n - 2;
    // arr[i] = i+1 before missing integer 
    // arr[i] = i+2 after missing integer
    
    while(left<=right){
        int mid = (left + right)/2;
        
        if(arr[mid] == mid + 1){ // missing integer lies at the right
            left = mid + 1;
        }else{ // arr[mid] == mid + 2 -> missing integer lies at the left
            right = mid - 1;
        }
    }
    
    return left + 1;

}

int main(){
    vector<int> v1 = {1, 2, 3, 4, 6, 7};
    vector<int> v2 = {1};
    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
    
    
    cout << MissingInteger(v1,7) << endl;
    cout << MissingInteger(v2,3) << endl;
    cout << MissingInteger(v3,9) << endl;
    
}

#include<bits/stdc++.h>
using namespace std;
//TC:O(n)
//SC:O(1)
int findMissingInteger(vector<int>&numbers,int n){
        if(numbers[0]!=1) return 1;
        
        for(int start=1;start<numbers.size();start++){
               if(numbers[start]-numbers[start-1]>1){
                  return numbers[start-1]+1;
                  
               }
        }
        return n;
       

}



int main(){
    
    int n;
    cin >> n;
    vector<int> arr(n - 1);
    
    for (int i = 0; i < n - 1; i++) cin >> arr[i];
    
    cout << findMissingInteger(arr, n);
    

    return 0;
}
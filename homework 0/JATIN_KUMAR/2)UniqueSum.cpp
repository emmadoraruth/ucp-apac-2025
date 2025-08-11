#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>



// timecomplexity= O(n);
// spaceComplexity= O(n);




int UniqueSum(int arr[],int size){
    unordered_map<int,int>mp;
    int sum=0;

    for(int i=0;i<size;i++){
        if(mp[arr[i]]==0){
            sum=sum+arr[i];
            mp[arr[i]]++;
        }
    }
    return sum;
    
}

int main(){
    int arr[]={1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
    int size=10;

    cout<<UniqueSum(arr,size);
}

// time taken = 10 min
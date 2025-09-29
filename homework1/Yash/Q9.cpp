// Question 9 : DedupArray
// Time Complexity : O(n^2) (worst-case)    Space Complexity: O(1)      Time Taken: 27 minutes 13 seconds

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> DedupArray (vector<int>& arr){

int SizeOfArray = arr.size();

for(int i = 0;i<SizeOfArray-1;){
    if(i>=arr.size()-1){break;}
    else if((arr[i]^arr[i+1])==0){
        arr.erase(arr.begin() + i+1);
    }
    else{
    i++;
    }
}

return arr;

}

void printVector(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main(){

    vector<int> arr1 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    cout << "Modified Array: ";
    printVector(DedupArray(arr1));   

    vector<int> arr2 = {0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15};
    cout << "Modified Array: ";
    printVector(DedupArray(arr2));   

    vector<int> arr3 = {1, 3, 4, 8, 10, 12};
    cout << "Modified Array: ";
    printVector(DedupArray(arr3));
    
    vector<int> arr4 = {};
    cout << "Modified Array: ";
    printVector(DedupArray(arr4));
    
    vector<int> arr5 = {0,0,0,0,0,0};
    cout << "Modified Array: ";
    printVector(DedupArray(arr5));

    return 0;
}
// Question 6 : Missing Integer
// Time Complexity : O(n)   Space Complexity: O(1)       Time Taken: 21 minutes 54 seconds

#include <iostream>
#include <vector>
using namespace std;



int MissingInteger(vector<int> arr, int n) {
    int SumOfValues = ((n + 1)*(n))/2;
    int answer = -1;

    if (arr.size() == 0) {
        cout << "Input array is empty. (Invalid Input) " ;
        return -1;
        cout<<endl;
    }
    for(int i : arr){
        SumOfValues -= i;
    }


    return SumOfValues;
}


int main(){
    vector<int> arr1 = {1, 2, 3, 4, 6, 7};
    int n1 = 7;
    cout << MissingInteger(arr1, n1) << endl;

    vector<int> arr2 = {1};
    int n2 = 2;
    cout << MissingInteger(arr2, n2) << endl;

    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
    int n3 = 12;
    cout << MissingInteger(arr3, n3) << endl;

    vector<int> arr4 = {};
    int n4 = 1;
    cout << MissingInteger(arr4, n4) <<endl;

    return 0;
}

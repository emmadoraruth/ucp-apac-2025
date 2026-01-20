 // Question 9 : Merge K Sorted Arrays ; Technique Used : Heap
// Time Taken : 25 minutes

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> MergeKSortedArrays(vector<vector<int>> arrays){
    vector<int> result;

    
    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > minHeap;

    
    for(int i = 0; i < arrays.size(); i++){
        if(arrays[i].size() > 0){
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    while(!minHeap.empty()){
        auto curr = minHeap.top();
        minHeap.pop();

        int value = curr[0];
        int arrIndex = curr[1];
        int elemIndex = curr[2];

        result.push_back(value);

       
        if(elemIndex + 1 < arrays[arrIndex].size()){
            minHeap.push({
                arrays[arrIndex][elemIndex + 1],
                arrIndex,
                elemIndex + 1
            });
        }
    }

    return result;
}

void Print(vector<int> arr){
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl;
}

int main(){

    vector<vector<int>> testcase1 = {
        {1, 2, 3, 4, 5},
        {1, 3, 5, 7, 9}
    };

    vector<vector<int>> testcase2 = {
        {1, 4, 7, 9},
        {2, 6, 7, 10, 11, 13, 15},
        {3, 8, 12, 13, 16}
    };

    Print(MergeKSortedArrays(testcase1));
    Print(MergeKSortedArrays(testcase2));

    return 0;
}

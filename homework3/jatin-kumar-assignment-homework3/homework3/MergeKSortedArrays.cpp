#include <iostream>
using namespace std;
#include <vector>
#include <queue>
// Merge k sorted arrays into one sorted array
// tc: O(N log k) where N is total number of elements and k is number of arrays
// sc: O(k) for the heap
// time taken: 38min

vector<int>mergeKSortedArrays(vector<vector<int>> arrays){
    vector<int> result;
    // Min-heap 
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > minHeap;

    

    for(int i = 0; i < arrays.size(); i++) {
        if(!arrays[i].empty()) {
            minHeap.push({arrays[i][0], {i, 0}}); // {value, {arrayIndex, elementIndex}}
        }
    }

    
    while(!minHeap.empty()) {
        auto [val, indices] = minHeap.top();
        minHeap.pop();
        result.push_back(val);
        
        int arrayIndex = indices.first;
        int elementIndex = indices.second;
        
        if(elementIndex + 1 < arrays[arrayIndex].size()) {
            minHeap.push({arrays[arrayIndex][elementIndex + 1], {arrayIndex, elementIndex + 1}});
        }
    }

    return result;

}

int main(){
    // Test Case 1: 2 sorted arrays
    // Input: [[1, 2, 3, 4, 5], [1, 3, 5, 7, 9]]
    // Expected Output: [1, 1, 2, 3, 3, 4, 5, 5, 7, 9]
    
    vector<vector<int>> arrays1 = {
        {1, 2, 3, 4, 5},
        {1, 3, 5, 7, 9}
    };
    
    cout << "Test Case 1 (2 arrays): ";
    vector<int> merged1 = mergeKSortedArrays(arrays1);
    for(int num : merged1) {
        cout << num << " ";
    }
    cout << endl << endl;

    // Test Case 2: 3 sorted arrays
    // Input: [[1, 4, 7, 9], [2, 6, 7, 10, 11, 13, 15], [3, 8, 12, 13, 16]]
    // Expected Output: [1, 2, 3, 4, 6, 7, 7, 8, 9, 10, 11, 12, 13, 13, 15, 16]
    
    vector<vector<int>> arrays2 = {
        {1, 4, 7, 9},
        {2, 6, 7, 10, 11, 13, 15},
        {3, 8, 12, 13, 16}
    };
    
    cout << "Test Case 2 (3 arrays): ";
    vector<int> merged2 = mergeKSortedArrays(arrays2);
    for(int num : merged2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
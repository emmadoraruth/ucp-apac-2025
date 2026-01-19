/*
Data Structure Used:
Heap (Min Heap / Priority Queue)

Algorithm:
Heap-based k-way merge

Approach:
Insert the first element of each sorted array into a min heap.
Repeatedly extract the minimum element and insert the next element
from the same array until the heap is empty.

Time Complexity:
- O(N log k)
  where N is the total number of elements across all arrays

Space Complexity:
- O(k) for the heap

Time Taken:
45 minutes
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
        vector<int> result;

        // min heap: (value, arrayIndex, elementIndex)
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > minHeap;

        // Initialize heap with first element of each array
        for (int i = 0; i < arrays.size(); i++) {
            if (!arrays[i].empty()) {
                minHeap.push({arrays[i][0], i, 0});
            }
        }

        // Extract-min and push next element from same array
        while (!minHeap.empty()) {
            auto [val, arrIdx, elemIdx] = minHeap.top();
            minHeap.pop();

            result.push_back(val);

            if (elemIdx + 1 < arrays[arrIdx].size()) {
                minHeap.push({
                    arrays[arrIdx][elemIdx + 1],
                    arrIdx,
                    elemIdx + 1
                });
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<vector<int>> input1 = {
        {1, 2, 3, 4, 5},
        {1, 3, 5, 7, 9}
    };

    vector<vector<int>> input2 = {
        {1, 4, 7, 9},
        {2, 6, 7, 10, 11, 13, 15},
        {3, 8, 12, 13, 16}
    };

    auto res1 = s.mergeKSortedArrays(input1);
    auto res2 = s.mergeKSortedArrays(input2);

    for (int x : res1) cout << x << " ";
    cout << endl;

    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}

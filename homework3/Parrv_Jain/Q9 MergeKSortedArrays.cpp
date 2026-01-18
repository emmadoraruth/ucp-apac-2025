#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
        vector<int> result;

        // Min heap: (value, array index, element index)
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > minHeap;

        // Push first element of each array
        for (int i = 0; i < arrays.size(); i++) {
            if (!arrays[i].empty()) {
                minHeap.push(make_tuple(arrays[i][0], i, 0));
            }
        }

        // Extract minimum and push next element from same array
        while (!minHeap.empty()) {
            int val = get<0>(minHeap.top());
            int arrIdx = get<1>(minHeap.top());
            int elemIdx = get<2>(minHeap.top());
            minHeap.pop();

            result.push_back(val);

            if (elemIdx + 1 < arrays[arrIdx].size()) {
                minHeap.push(make_tuple(
                    arrays[arrIdx][elemIdx + 1],
                    arrIdx,
                    elemIdx + 1
                ));
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> arrays = {
        {1, 2, 3, 4, 5},
        {1, 3, 5, 7, 9}
    };

    Solution s;
    vector<int> res = s.mergeKSortedArrays(arrays);

    for (int x : res)
        cout << x << " ";

    return 0;
}

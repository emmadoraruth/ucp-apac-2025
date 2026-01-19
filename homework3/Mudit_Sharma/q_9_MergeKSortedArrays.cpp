// Question 9: MergeKSortedArrays
// Given an array of k sorted arrays, merge the k arrays into a single sorted array.

// Examples:
// Input: 2, [[1, 2, 3, 4, 5], [1, 3, 5, 7, 9]]
// Output: [1, 1, 2, 3, 3, 4, 5, 5, 7, 9]
// Input: 3, [[1, 4, 7, 9], [2, 6, 7, 10, 11, 13, 15], [3, 8, 12, 13, 16]]
// Output: [1, 2, 3, 4, 6, 7, 7, 8, 9, 10, 11, 12, 13, 13, 15, 16]

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &arrays)
{
    vector<int> result;

    priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,greater<tuple<int, int, int>>>minHeap;
    for (int i = 0; i < arrays.size(); i++)
    {
        if (!arrays[i].empty())
        {
            minHeap.push(make_tuple(arrays[i][0], i, 0));
        }
    }
    while (!minHeap.empty())
    {
        auto t = minHeap.top();
        int val = get<0>(t);
        int arrIdx = get<1>(t);
        int elemIdx = get<2>(t);

        minHeap.pop();

        result.push_back(val);

        if (elemIdx + 1 < arrays[arrIdx].size())
        {
            minHeap.push(make_tuple(
                arrays[arrIdx][elemIdx + 1],
                arrIdx,
                elemIdx + 1));
        }
    }

    return result;
}
int main()
{
    vector<vector<int>> arrays = {
        {1, 2, 3, 4, 5},
        {1, 3, 5, 7, 9}};

    vector<int> res = mergeKSortedArrays(arrays);

    for (int x : res)
        cout << x << " ";
}

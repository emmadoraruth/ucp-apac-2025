// Question 9: MergeKSortedArrays
// Given an array of k sorted arrays, merge the k arrays into a single sorted array.

// Examples:
// Input: 2, [[1, 2, 3, 4, 5], [1, 3, 5, 7, 9]]
// Output: [1, 1, 2, 3, 3, 4, 5, 5, 7, 9]
// Input: 3, [[1, 4, 7, 9], [2, 6, 7, 10, 11, 13, 15], [3, 8, 12, 13, 16]]
// Output: [1, 2, 3, 4, 6, 7, 7, 8, 9, 10, 11, 12, 13, 13, 15, 16]

//-------------------------------------------------------------------------------------------------------
//I used Min heap where i pushed first integer of each array so 
//and then whenever i pop one smallest element from min heap
//then i will push the next element from that array into the heap if more elements are left

//Time complexity : O(nXm)
//Space complexity: O(nXm) in min heap and also in the answer array

#include <bits/stdc++.h>
using namespace std;

std::vector<int> mergeKSortedArrays(std::vector<std::vector<int>> &arrays)
{
    std::vector<int> result;

    std::priority_queue<std::tuple<int, int, int>,std::vector<std::tuple<int, int, int>>,std::greater<std::tuple<int, int, int>>>minHeap;
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
    std::vector<std::vector<int>> arrays1 = {
        {1, 2, 3, 4, 5},
        {1, 3, 5, 7, 9}};

    std::vector<int> res1 = mergeKSortedArrays(arrays1);
    for (int x : res1)
        std::cout << x << " ";
    
    std::cout<<std::endl;

    std::vector<std::vector<int>> arrays2 = {
       {1, 4, 7, 9}, {2, 6, 7, 10, 11, 13, 15}, {3, 8, 12, 13, 16}};

    std::vector<int> res2 = mergeKSortedArrays(arrays2);
    for (int x : res2)
        std::cout << x << " ";  
    std::cout<<std::endl;
}

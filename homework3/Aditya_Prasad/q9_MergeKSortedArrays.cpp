// DS/Algo used - Priority Queue
//
// Time Complexity: O(n log k)
// Memory Complexity: O(n)
//
// where k = number of sorted arrays and n = total number of elements across all arrays

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> kSortedArrays){
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
    vector<int> sortedArray;

    int k = kSortedArrays.size();
    
    for (int i = 0; i < k; i++){
        q.push({kSortedArrays[i][0], {i, 0}});
    }

    while(!q.empty()){
        int currElement = q.top().first;
        int arrayIndex = q.top().second.first;
        int index = q.top().second.second;

        sortedArray.push_back(currElement);

        q.pop();
        index++;

        if(index < kSortedArrays[arrayIndex].size()){
            q.push({kSortedArrays[arrayIndex][index], {arrayIndex, index}});
        }
    }

    return sortedArray;
}

int main(){
    vector<int> ansTC1 = mergeKSortedArrays({{1, 2, 3, 4, 5}, {1, 3, 5, 7, 9}});
    vector<int> ansTC2 = mergeKSortedArrays({{1, 4, 7, 9}, {2, 6, 7, 10, 11, 13, 15}, {3, 8, 12, 13, 16}});

    for(int num : ansTC1){
        cout << num << " ";
    }

    cout << endl;

    for(int num : ansTC2){
        cout << num << " ";
    }
}

// Time Taken - 22 min
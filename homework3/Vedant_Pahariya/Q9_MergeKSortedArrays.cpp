// Given an array of k sorted arrays, merge the k arrays into a single sorted array.

#include <bits/stdc++.h>
using namespace std;

// So the first brute force method came into my mind is that just simply collect all the elements in a single array then sort all of them.
// Time Comlexity: O(n) for iterating all elements + O(nlogn) for sorting so effectively O(nlogn) where n is total no. of elements combining all arrays
// Space Complexity: O(n) for vector storing all combined arrays
vector<int> sorted1(int k, vector<vector<int>> input){
    vector<int> result;

    for(int i=0; i<k; i++){
        for(int j=0; j<input[i].size(); j++){
            result.push_back(input[i][j]);
        }
    }

    sort(result.begin(), result.end());
    return result;
}

// So then to perform better than the above, thinking of small example lets says two arrays, we can merge them using two pointer approach so time complexity of that is O(n), extending this to lets say three arrays then we can have three pointers and each time if we pick the smallest one (this gives idea of some kind of min heap) and pushing the new element in the heaping after popping out one. So, there will be total k elements in the heap at anytime, each element of heap is pointer to the array.

// Time Complexity: Heap is always of size of K or less, so pushing any element into it is O(logk). This we are doing for n times so Total time complexity is O(nlogk)
// Space Complexity: O(n) for result vector + O(k) for heap so total O(n+k)
vector<int> sorted2(int k, vector<vector<int>> input){
    vector<int> result;
    priority_queue<tuple<int,int, int>, vector<tuple<int,int, int>>, greater<tuple<int, int, int>>> minHeap;

    for(int i =0 ; i<k; i++){
        if(!input[i].empty()){
            minHeap.push({input[i][0], i, 0});
        }
    }

    while(!minHeap.empty()){
        auto t = minHeap.top();
        minHeap.pop();

        int val = get<0>(t);
        int arrIdx = get<1>(t);
        int eleIdx = get<2>(t);

        result.push_back(val);
        if(eleIdx + 1 < input[arrIdx].size()){
            minHeap.push(make_tuple(input[arrIdx][eleIdx + 1], arrIdx, eleIdx + 1));
        }
    }

    return result;
}


int main(){ 
    vector<vector<int>> input1 = {{1,2,3,4,5},{1,3,5,7,9}};

    vector<vector<int>> input2 = 
    {{1, 4, 7, 9}, {2, 6, 7, 10, 11, 13, 15}, {3, 8, 12, 13, 16}};

    vector<int> out1= sorted1(2,input1);

    for(auto it: out1){
        cout << it << " ";
    }
    cout << "\n";

    vector<int> out2 = sorted1(3, input2);

    for(auto it: out2){
        cout << it << " ";
    }
}
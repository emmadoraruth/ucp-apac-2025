#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// T.C = O(n log n) due to sorting
// S.C = O(n) for storing merged intervals
// Approach: Sort intervals by start time, then iterate and merge overlapping intervals.
// TIMETAKEN:30MINS

vector<pair<int,int>> MergeIntervals(vector<pair<int,int>> intervals) {
    sort(intervals.begin(), intervals.end());
    vector<pair<int,int>> merge;
    merge.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first <= merge.back().second) {
            merge.back().second = max(merge.back().second, intervals[i].second);
        } else {
            merge.push_back(intervals[i]);
        }
    }
    return merge;
}

void print(const vector<pair<int,int>>& intervals) {
    for (auto interval : intervals) {
        cout << "(" << interval.first << "," << interval.second << ")";
    }
    cout << endl;
}

int main(){
    vector<pair<int,int>> v1 = {{2,3},{4,8},{1,2},{5,7},{9,12}};
    print(MergeIntervals(v1)); // Expected: (1,3)(4,8)(9,12)

    vector<pair<int,int>> v2 = {{5,8},{6,10},{2,4},{3,6}};
    print(MergeIntervals(v2)); // Expected: (2,10)

    vector<pair<int,int>> v3 = {{10,12},{5,6},{7,9},{1,3}};
    print(MergeIntervals(v3)); // Expected: (1,3)(5,6)(7,9)(10,12)
}
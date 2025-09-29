/*
Time Complexity: O(n log n)   // Sorting intervals
Space Complexity: O(n)        // For storing merged intervals
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> mergeIntervals(vector<pair<int,int>>& intervals) {
    if (intervals.empty()) return {};

    // Sort intervals by start
    sort(intervals.begin(), intervals.end());

    vector<pair<int,int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first <= merged.back().second) {
            // Overlap, merge intervals
            merged.back().second = max(merged.back().second, intervals[i].second);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

// Helper function to print intervals
void printIntervals(vector<pair<int,int>> intervals) {
    for (auto p : intervals) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;
}

// Test cases
int main() {
    vector<pair<int,int>> v1 = {{2,3},{4,8},{1,2},{5,7},{9,12}};
    printIntervals(mergeIntervals(v1)); // Expected: (1,3) (4,8) (9,12)

    vector<pair<int,int>> v2 = {{5,8},{6,10},{2,4},{3,6}};
    printIntervals(mergeIntervals(v2)); // Expected: (2,10)

    vector<pair<int,int>> v3 = {{10,12},{5,6},{7,9},{1,3}};
    printIntervals(mergeIntervals(v3)); // Expected: (1,3) (5,6) (7,9) (10,12)
    
    return 0;
}

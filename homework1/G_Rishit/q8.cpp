#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> intervals) {
    if (intervals.empty()) return intervals;
    
    // Sort intervals by start time
    sort(intervals.begin(), intervals.end());
    
    vector<pair<int, int>> merged;
    merged.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        pair<int, int>& last = merged.back();
        pair<int, int> current = intervals[i];
        
        // If current interval overlaps with last merged interval
        if (current.first <= last.second) {
            // Merge intervals by updating end time if needed
            last.second = max(last.second, current.second);
        } else {
            // No overlap, add as new interval
            merged.push_back(current);
        }
    }
    
    return merged;
}

void printIntervals(const vector<pair<int, int>>& intervals) {
    for (auto p : intervals) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

int main() {
    vector<pair<int, int>> test1 = {{2, 3}, {4, 8}, {1, 2}, {5, 7}, {9, 12}};
    vector<pair<int, int>> result1 = mergeIntervals(test1);
    printIntervals(result1);  // Expected: (1, 8) (9, 12) or similar merged result
    
    vector<pair<int, int>> test2 = {{5, 8}, {6, 10}, {2, 4}, {3, 6}};
    vector<pair<int, int>> result2 = mergeIntervals(test2);
    printIntervals(result2);  // Expected: (2, 10)
    
    vector<pair<int, int>> test3 = {{10, 12}, {5, 6}, {7, 9}, {1, 3}};
    vector<pair<int, int>> result3 = mergeIntervals(test3);
    printIntervals(result3);  // Expected: (1, 3) (5, 6) (7, 9) (10, 12)
    
    return 0;
}

// T.C = O(n log n) due to sorting
// S.C = O(n) for storing merged intervals
// Approach: Sort intervals by start time, then merge overlapping intervals
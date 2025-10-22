// Problem Statement
/*Given a list of integer pairs representing the low and high end of an interval, inclusive, return a list in which overlapping intervals are merged.
*/

// Technique: Sorting the array
// Time Complexity: O(n log n), n is the number of intervals
// Space Complexity: O(n), for storing merged intervals

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> mergeIntervals(vector<pair<int,int>> intervals){
    if(intervals.empty()) return {};

    // Sort intervals based on starting times
    sort(intervals.begin(), intervals.end());
    // This step will take nlogn time where n is the number of intervals

    // printing the sorted intervals
    // for(auto interval: intervals){
    //     cout << "[" << interval.first << ", " << interval.second << "] ";
    // }

    vector<pair<int,int>> merged;
    merged.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].first <= merged.back().second){
            // Overlapping intervals, merge them
            merged.back().second = max(merged.back().second, intervals[i].second);
        } else {
            // No overlap, add the current interval to merged list
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main(){
    vector<pair<int,int>> intervals = {{1,3},  {5,7},{2,4}, {6,8}};
    vector<pair<int,int>> merged = mergeIntervals(intervals);

    cout << "\nMerged Intervals: ";
    for(auto interval: merged){
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    cout << "\n";

    // Input: [(2, 3), (4, 8), (1, 2), (5, 7), (9, 12)]
    intervals = {{2,3}, {4,8}, {1,2}, {5,7}, {9,12}};
    merged = mergeIntervals(intervals);

    cout << "\nMerged Intervals: ";
    for(auto interval: merged){
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    cout << "\n";

    // Input: [(5, 8), (6, 10), (2, 4), (3, 6)]
    intervals = {{5,8}, {6,10}, {2,4}, {3,6}};
    merged = mergeIntervals(intervals);

    cout << "\nMerged Intervals: ";
    for(auto interval: merged){
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    cout << "\n";
}

// Thinking Process
/*
Thought of sorting from the starting and comparing the first element of interval with previous interval second element.

Second way I thought of to do this is using masked array without sorting (O(n)). lets say number are within the range 1 to x in all intervals then on seeing any interval (a,b), update the indices of masked array from a to b with 1. When next interval (c,d) comes, make c to d 1 and so on. At the end, take all the ranges with 1. But this approach will take lot of space if x/interval size is large so sorting algorithm is preferred because of consistency.
*/
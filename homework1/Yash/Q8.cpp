// Question 8 : Merged Intervals 
// Time Complexity : O(nlogn)   Space Complexity: O(n)     Time Taken: 38 minutes 7 seconds

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool error_test(vector<pair<int,int>>& intervals){
    if(intervals.size() == 0){
        return true;
    }
    return false;
}

vector<pair<int,int>> MergeIntervals(vector<pair<int,int>>& intervals){
    if(error_test(intervals)){
        cout << "Input intervals list is empty. (Invalid Input)";
        return {};
    }

    sort(intervals.begin(), intervals.end()); // O(nlogn) is the time complexity of the sorting

    vector<pair<int,int>> merged;
    merged.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].first <= merged.back().second){
            merged.back().second = max(merged.back().second, intervals[i].second);
        }
        else{
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

void printIntervals(const vector<pair<int,int>>& intervals){
    for(auto interval : intervals){
        cout << "[" << interval.first << "," << interval.second << "] ";
    }
    cout << endl;
}

int main(){
    vector<pair<int,int>> intervals1 = {{2, 3}, {4, 8}, {1, 2}, {5, 7}, {9, 12}};
    vector<pair<int,int>> merged1 = MergeIntervals(intervals1);
    printIntervals(merged1);

    vector<pair<int,int>> intervals2 = {{5, 8}, {6, 10}, {2, 4}, {3, 6}};
    vector<pair<int,int>> merged2 = MergeIntervals(intervals2);
    printIntervals(merged2);

    vector<pair<int,int>> intervals3 = {{10, 12}, {5, 6}, {7, 9}, {1, 3}};
    vector<pair<int,int>> merged3 = MergeIntervals(intervals3);
    printIntervals(merged3);

    return 0;
}
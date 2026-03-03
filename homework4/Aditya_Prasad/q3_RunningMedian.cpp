// Technique : Maintain two heaps
// T.C : O(n*logn)
// M.C : O(n)

#include <bits/stdc++.h>
using namespace std;

vector<double> runningMedian(vector<int>& nums) {
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // maxHeap.size() == minHeap.size() -> 2 median (two values - avg)
    // else there will be 1 median -> maxHeap.top() 
    vector<double> answer;

    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];

        if (maxHeap.empty() == true || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > 1 +  minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (minHeap.size() > 1 + maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if ((maxHeap.size() == minHeap.size())) {
            double median = (maxHeap.top() + minHeap.top()) / 2.0;
            answer.push_back(median);
        } else {
            if (maxHeap.size() > minHeap.size()) answer.push_back(maxHeap.top());
            else answer.push_back(minHeap.top());
        }
    }

    return answer;
}
int main() {
    vector<int> tc1 = {1, 11, 4, 15, 12};

    vector<double> answer = runningMedian(tc1);

    for (double ans : answer) {
        cout << ans <<  " ";
    }

}

// Time Taken : 25 mins
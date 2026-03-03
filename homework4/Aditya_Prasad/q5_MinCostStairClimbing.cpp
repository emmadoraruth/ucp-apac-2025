// Technique : Dynamic programming (Memoization / Tabulation)
// T.C : O(n)
// M.C : O(n) - Memoization, O(1) - Tabulation
// where n - costs.size()

#include <bits/stdc++.h>
using namespace std;

int minCost (int i, vector<int>& costs, vector<int>& dp) {
    if (i <= 1) return 0;

    if (dp[i] != -1) return dp[i];
    int cost = 0;

    int oneStep = costs[i - 1] + minCost(i - 1, costs, dp);
    int twoStep = costs[i - 2] + minCost(i - 2, costs, dp);

    return dp[i] = min(oneStep, twoStep);
}

int minCostIterative(vector<int>& costs) {
    int prev2 = 0, prev1 = 0;

    for (int i = 2; i <= costs.size(); i++) {
        int minCost = min(prev2 + costs[i - 2], prev1 + costs[i - 1]);
        prev2 = prev1;
        prev1 = minCost;
    }

    return prev1;
}
int main() {
    vector<int> costs1 = {4, 1, 6, 3, 5, 8};
    vector<int> costs2 = {11, 8, 3, 4, 9, 13, 10};

    vector<int> dp;
    dp.assign(costs1.size() + 1, -1);
    cout << minCost(costs1.size(), costs1, dp) << endl;
    cout << minCostIterative(costs1) << endl;
    dp.assign(costs2.size() + 1, -1);
    cout << minCost(costs2.size(), costs2, dp) << endl;
    cout << minCostIterative(costs2) << endl;
    return 0;
}

// Time Taken - 20 mins
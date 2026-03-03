// Technique : Dynamic programming (Memoization)
// T.C : O(n*k)
// M.C : O(n*k)
// where n = coins.size(), k = targetSum


#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int>& coins, int targetSum, vector<vector<int>>& dp) {
    if (targetSum == 0) return 1;

    if (i == coins.size()) return 0;

    if (dp[i][targetSum] != -1) return dp[i][targetSum];
    int ways = 0;

    if (targetSum - coins[i] >= 0) ways += f(i, coins, targetSum - coins[i], dp);
    ways += f(i + 1, coins, targetSum, dp);

    return dp[i][targetSum] = ways;
}

int coinChange(int targetSum, vector<int>& coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int> (targetSum + 1, -1));
    return f(0, coins, targetSum, dp);
}

int main() {
    vector<int> coins = {2, 5, 10};
    cout << coinChange(20, coins) << endl;
    cout << coinChange(15, coins);
    return 0;
}

// Time Taken : 15 mins
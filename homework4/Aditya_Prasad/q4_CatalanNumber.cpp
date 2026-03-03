// Technique : Dynamic programming (Memoization)
// T.C : O(n^2)
// M.C : O(n)


#include <bits/stdc++.h>
using namespace std;

int nthCatalanNumber(int n, vector<int>& dp) {
    if (n <= 1) return dp[n] = 1;

    if(dp[n] != -1) return dp[n];

    int catalanNumber = 0;

    for (int i = 0; i < n; i++) {
        catalanNumber += nthCatalanNumber(i, dp)*nthCatalanNumber(n - i - 1, dp);
    }

    return dp[n] = catalanNumber;
}

vector<int> catalanNumberstillN(int n) {
    vector<int> dp(n + 1, -1);

    for (int i = 0; i <= n; i++) {
        dp[i] = nthCatalanNumber(i, dp);
    }

    return dp;
}

int main() {
    vector<int> ans1 = catalanNumberstillN(1);
    vector<int> ans2 = catalanNumberstillN(5);

    for (int ans : ans1) {
        cout << ans << " ";
    }

    cout << endl;

    for (int ans : ans2) {
        cout << ans << " ";
    }
}

// Time Taken : 30 mins
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> firstKBinaryNumbers(int k) {
        vector<string> result;
        if (k <= 0) return result;

        queue<string> q;
        q.push("0");

        while (result.size() < k) {
            string curr = q.front();
            q.pop();

            result.push_back(curr);

            q.push(curr + "0");
            q.push(curr + "1");
        }

        return result;
    }
};

int main() {
    Solution s;
    int k = 5;

    vector<string> ans = s.firstKBinaryNumbers(k);
    for (auto &x : ans)
        cout << x << " ";

    return 0;
}

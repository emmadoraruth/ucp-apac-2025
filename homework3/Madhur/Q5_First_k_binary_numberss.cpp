/*
Approach:
Generate binary numbers from 0 to k−1 by converting each integer to its binary string
representation and storing them in an array.

Time Complexity:
- O(k log k)   // each number takes log k bits to get convert

Space Complexity:
- O(k log k)

Time Taken:
28 minutes
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> firstKBinaryNumbers(int k) {
        vector<string> result;

        for (int i = 0; i < k; i++) {
            result.push_back(bitset<32>(i).to_string());
        }

        // remove leading zeros
        for (string &s : result) {
            int pos = s.find('1');
            if (pos != string::npos)
                s = s.substr(pos);
            else
                s = "0";
        }

        return result;
    }
};

int main() {
    Solution s;

    int k1 = 5;
    int k2 = 10;

    auto res1 = s.firstKBinaryNumbers(k1);
    auto res2 = s.firstKBinaryNumbers(k2);

    for (auto &x : res1) cout << x << " ";
    cout << endl;

    for (auto &x : res2) cout << x << " ";
    cout << endl;

    return 0;
}

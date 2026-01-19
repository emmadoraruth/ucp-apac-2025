#include <bits/stdc++.h>
using namespace std;

//I used queue and applied BFS algo, It took me around 25 minutes to finish
// Time complexity: O(k)
//Sapce complexity: O(k)

vector<string> firstkbinarynumbers(int k) 
{
    vector<string> result;
    if (k <= 0) return result;
    queue<string> q;
    q.push("1");
    result.push_back("0");

    while ((int)result.size() < k) 
    {
        string curr = q.front();
        q.pop();
        result.push_back(curr);
        q.push(curr + "0");
        q.push(curr + "1");
    }

    return result;
}

int main() {
    int k1 = 5;
    int k2 = 10;

    vector<string> res1 = firstkbinarynumbers(k1);
    vector<string> res2 = firstkbinarynumbers(k2);

    for (int i = 0; i < (int)res1.size(); i++)
        cout << res1[i] << " ";
    cout << endl;

    for (int i = 0; i < (int)res2.size(); i++)
        cout << res2[i] << " ";
    cout << endl;
    return 0;
}
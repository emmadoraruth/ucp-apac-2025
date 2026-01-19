#include <bits/stdc++.h>
using namespace std;

//I used priority queue (min heap) and it took me around 25 min to finish
//Time complexity: O(N log k)
//Space complexity: O(k)

vector<int> mergeksortedarray(vector<vector<int> >& array) 
{
    vector<int> result;
    priority_queue<pair<int, pair<int, int> >,vector<pair<int, pair<int, int> > >,greater<pair<int, pair<int, int> > > > pq;

    for (int i = 0; i < (int)array.size(); i++) 
    {
        if (!array[i].empty()) 
        {
            pq.push(make_pair(array[i][0], make_pair(i, 0)));
        }
    }

    while (!pq.empty()) 
    {
        pair<int, pair<int, int> > curr = pq.top();
        pq.pop();

        int value = curr.first;
        int index = curr.second.first;
        int elem = curr.second.second;

        result.push_back(value);

        if (elem + 1 < (int)array[index].size()) 
        {
            pq.push(make_pair(array[index][elem + 1],make_pair(index, elem + 1)));
        }
    }

    return result;
}

int main() {
    vector<vector<int> > input1;
    input1.push_back({1, 2, 3, 4, 5});
    input1.push_back({1, 3, 5, 7, 9});

    vector<int> res1 = mergeksortedarray(input1);
    for (int i = 0; i < (int)res1.size(); i++)
        cout << res1[i] << " ";
    cout << endl;

    vector<vector<int> > input2;
    input2.push_back({1, 4, 7, 9});
    input2.push_back({2, 6, 7, 10, 11, 13, 15});
    input2.push_back({3, 8, 12, 13, 16});

    vector<int> res2 = mergeksortedarray(input2);
    for (int i = 0; i < (int)res2.size(); i++)
        cout << res2[i] << " ";
    cout << endl;

    return 0;
}

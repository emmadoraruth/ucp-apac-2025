#include <bits/stdc++.h>
using namespace std;

//it took around 20 min
//I used sorting algorithm (in built) and then merged it, as this is one of the most common strategy for this model of questions
// time -> o(nlogn) (sorting) , space -> o(n) (to store merged intervals)

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> interval(n);
    for (int i =0; i<n; i++)
    {
        cin >> interval[i].first >> interval[i].second;
    }

    sort(interval.begin(),interval.end());
    vector<pair<int,int>>sorted;
    int start = interval[0].first;
    int end = interval[0].second;

    for(int i = 1; i<n; i++)
    {
        if(interval[i].first <= end)
        {
            end = max(end,interval[i].second);
        }else
        {
            sorted.push_back({start,end});
            start = interval[i].first;
             end = interval[i].second;
        }
    }
    sorted.push_back({start,end});

    for (int i =0; i<n; i++)
    {
        cout << "(" << sorted[i].first << " " << sorted[i].second << ")" << " ";
    }

    return 0;


}
#include <bits/stdc++.h>
using namespace std;

class PriorityQueue 
{
private:
    vector<pair<string, int>> arr;

    int parent(int i) 
    {
        return (i - 1) / 2;
    }

    int left(int i) 
    {
        return 2 * i + 1;
    }

    int right(int i) 
    {
        return 2 * i + 2;
    }

    void heapifyup(int i) 
    {
        while (i > 0 && arr[parent(i)].second < arr[i].second) 
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapifydown(int i) 
    {
        int high = i;
        int l = left(i);
        int r = right(i);

        if (l < arr.size() && arr[l].second > arr[high].second) 
        {
            high = l;
        }

        if (r < arr.size() && arr[r].second > arr[high].second) 
        {
            high = r;
        }

        if (high != i) 
        {
            swap(arr[i], arr[high]);
            heapifydown(high);
        }
    }

public:
    string top() 
    {
        if (arr.empty()) 
        {
            return "";
        }
        return arr[0].first;
    }

    void insert(string x, int weight) 
    {
        arr.push_back({x, weight});
        heapifyup(arr.size() - 1);
    }

    void remove() 
    {
        if (arr.empty()) 
        {
            return;
        }

        arr[0] = arr.back();
        arr.pop_back();

        if (!arr.empty()) 
        {
            heapifydown(0);
        }
    }
};

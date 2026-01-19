#include <bits/stdc++.h>
using namespace std;

class Heap 
{
private:
    vector<int> arr;  
    void heapifyup(int i) 
    {
        while (i > 0) 
        {
            int parent = (i - 1) / 2;
            if (arr[parent] <= arr[i])
            {
                break;
            }
            swap(arr[parent], arr[i]);
            i = parent;
        }
    }

    void heapifydown(int i) 
    {
        int n = arr.size();
        while (true) 
        {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int low = i;

            if (l < n && arr[l] < arr[low])
            {
                low = l;
            }
            if (r < n && arr[r] < arr[low])
            {
                low = r;
            }
            if (low == i)
            {
                break;
            }
            swap(arr[i], arr[low]);
            i = low;
        }
    }

public:
    int top() 
    {
        if (arr.empty())
        {
            cout << "Heap is empty\n";
            return -1;
        }
            
        return arr[0];
    }
    void insert(int x) 
    {
        arr.push_back(x);
        heapifyup(arr.size() - 1);
    }

    void remove() 
    {
        if (arr.empty())
        {
            cout << "Heap is empty\n";
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

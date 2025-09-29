#include <bits/stdc++.h>
using namespace std;

// it took me around 35 min to write this code and also, i also wrote both brute force and optimized code 
int countzerosumpairs(const vector <int>& arr, unordered_map<int,int>& frequency,int m)
{
    int x = 0;

    for(int i = 0; i<m; i++)
    {
        if(frequency[i] != 0 && frequency[-i] != 0 )
        {int n = min(frequency[i],frequency[-i]);
        x = x + n;
        if(frequency[0] == 2)
        {
            x = x-1;
        }
        }
    }
    return x;

}

int countzerosumpairs_multiple_index(const vector <int>& arr, unordered_map<int,int>& frequency,int m)
{
    int x = 0;

    for(int i = 0; i<m; i++)
    {
        if(frequency[i] != 0 && frequency[-i] != 0 )
        {int n = max(frequency[i],frequency[-i]);
        x = x + n;
        if(frequency[0] == 2)
        {
            x = x-1;
        }
        }
    }
    return x;

}



int main()
{
    int m;
    cin >> m;
    vector <int> arr(m);

    for(int i =0; i<m; i++)
    {
        cin >> arr[i];
    }

  
   
    unordered_map <int,int> frequency;

    for(int i = 0; i<m; i++)
    {
        frequency[arr[i]]++;
    }

    int res1 = countzerosumpairs(arr,frequency,m);
    int res2 = countzerosumpairs_multiple_index(arr,frequency,m);


    cout << res1 << endl;
    cout << res2 << endl;

    return 0;



}


// brute force condition 1
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;
    vector<int> arr(m);

    for(int i = 0; i<m; i++)
    {
        cin >> arr[i];
    }

    
    int y = 0;
    

    for (int j = 0; j<m; j++)
    {
       
        int x = arr[j];
        int z = j + 1;
        int i;

        for (i = z; i<m; i++)
        {
           if(x + arr[i] == 0)
            { 
                y++;
               
                arr[i] = 1000;
                arr[j] = 1000;
                 break;
            }
        }
    }

    cout << y << endl;
    return 0;
}

brute force follow up


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;
    vector<int> arr(m);

    for(int i = 0; i<m; i++)
    {
        cin >> arr[i];
    }

    
    int y = 0;
    

    for (int j = 0; j<m; j++)
    {
       
        int x = arr[j];
        int z = j + 1;
        int i;

        for (i = z; i<m; i++)
        {
           if(x + arr[i] == 0)
            { 
                y++;
            }
        }
    }

    cout << y << endl;
    return 0;
}
*/
// T.C = O(n)
// M.C = O(n) we're modifying the input
// Time Taken = 10 min 
// Forward/backward two-pointer


#include <bits/stdc++.h>
using namespace std;

vector<int> DedupArray(vector<int> v){
    int i = 0, j = 1;
    
    // 1 1 1 2 3 3 4 4 4 = 1 2 3 4

    for(int j=1;j<v.size();j++){
        if(v[j] != v[i]){
            v[i+1] = v[j];
            i++;
        }
    }
    
    v.resize(i+1);
    return v;
}

int main() {
    vector<int> ans = DedupArray({1, 2, 2, 3, 3, 3, 4, 4, 4, 4});
    
    for(int num : ans){
        cout << num << " ";
    }

}

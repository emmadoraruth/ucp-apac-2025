// DS/Algo used - BFS

// Time Complexity - O(k)

// Memory Complexity - O(k)

#include <bits/stdc++.h>
using namespace std;

void FirstKBinaryNumbers(int k){
    cout << "0" << " ";

    if (k == 1) return;

    queue<string> q;
    q.push("1");

    for (int i = 0; i < k - 1; i++){
        string curr = q.front();
        q.pop();

        cout << curr << " ";

        q.push(curr + "0");
        q.push(curr + "1");
    }
}

int main(){
    FirstKBinaryNumbers(5);
    FirstKBinaryNumbers(10);

}

// Time Taken - 20 min
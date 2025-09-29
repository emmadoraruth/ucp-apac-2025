#include <bits/stdc++.h>
using namespace std;

string FirstOccurrence(string& s){
    unordered_map<char,int> umap;
    string ans;
    for (char &c:s){
        if (umap[c]==0){ //detects first occurence of a character and marks it as recorded
            ans.push_back(c);
            umap[c]+=1;
        }
    }
    return ans;
}

int main(){
    string line;
    getline(cin, line);
    cout<< endl<< FirstOccurrence(line)<< endl;
    return 0;
}
//took me about 8 minutes for this question
// T.C O(n)   S.C O(n)
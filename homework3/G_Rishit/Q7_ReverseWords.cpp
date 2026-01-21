#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("Q7_input.txt");
    ofstream out("Q7_output.txt");
    
    string line;
    getline(in,line);
    
    vector<string>words;
    stringstream ss(line);
    string word;
    while(ss>>word){
        words.push_back(word);
    }
    
    reverse(words.begin(),words.end());
    
    for(int i=0;i<words.size();i++){
        out<<words[i];
        if(i<words.size()-1) out<<" ";
    }
    out<<endl;
    
    in.close();
    out.close();
    return 0;
}

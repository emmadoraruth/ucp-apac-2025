#include<bits/stdc++.h>
using namespace std;
//TC:O(n)
//SC:O(v) where v is the no. of vowels in the string
bool checkVowel(char character){
     
    string vowels = "aeiouAEIOU";
    return vowels.find(character) != string::npos;
 
}

string reverseVowels(string &input){
        vector<char>vowels;
        for(char character:input ){
            if(checkVowel(character)){
                 vowels.push_back(character);

            }
        }
        if(vowels.size()==0) return input;
        reverse(vowels.begin(),vowels.end());
        int j=0;
        for(int i=0;i<input.size();i++){
             if(checkVowel(input[i])){
                 input[i]=vowels[j];
                 j++;
             }

        }
        return input;

}






int main(){

    string s;
    cin >> s;
    cout << reverseVowels(s);
    return 0;

}
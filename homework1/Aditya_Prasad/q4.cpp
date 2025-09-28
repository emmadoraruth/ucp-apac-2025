#include <bits/stdc++.h>
using namespace std;

string resultingText(string s){
	int n = s.size();
	string finalString; 

	for(char c : s){ // O(n)
		if(c!='#') finalString.push_back(c); //O(1)
		else if(finalString.size()>0){
			finalString.pop_back(); // O(1)
		}
	}

	return finalString;
}

bool BackspaceStringCompare(string s1, string s2){
	return resultingText(s1) == resultingText(s2);
}

int main(){
	cout << BackspaceStringCompare("abcdef###xyz","abcw#xyz") << endl;
	cout << BackspaceStringCompare("Uber Career Prep","u#Uber Careee#r Prep") << endl;
	cout << BackspaceStringCompare("abcdef###xyz","abcdefxyz###");
	return 0;
}
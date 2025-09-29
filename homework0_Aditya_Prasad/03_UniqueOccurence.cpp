// int n = str.size()
// T.C = O(n) because we're traversing the array once and each unordered_set operation is O(1) on average.
// M.C = O(n) because we're storing at max n elements.
// Time Taken : 5 min


#include <bits/stdc++.h>
using namespace std;

string uniqueOccurence(string str){
	unordered_set<char> firstChar;
	string ans;

	for(char c : str){
		if(firstChar.find(c)==firstChar.end()){ 
			ans += c;
		}
		firstChar.insert(c);
	}

	return ans;
}

int main() {

	/*	Input String: "abracadabra"
	Output: "abrcd"

	Input String: "Uber Career Prep"
	Output: "Uber CaPp"

	Input String: "zzyzx"
	Output: "zyx"*/

	string tC1 = "abracadabra";
	string tC2 = "Uber Career Prep";
	string tC3 = "zzyzx";

	cout << uniqueOccurence(tC1) << endl;
	cout << uniqueOccurence(tC2) << endl;
	cout << uniqueOccurence(tC3) << endl;
	
	return 0;
}


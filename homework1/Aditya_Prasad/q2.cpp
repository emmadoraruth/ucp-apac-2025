//T.C - O(n) since each pointer will traverse the string once - O(n), rest of the operations like lookup in unoredered set are O(1) in average case
//M.C - O(1) since we only created an unordered set of length 10 which is a constant wrt input string
//20 mins

#include <bits/stdc++.h>
using namespace std;

string reverseVowels(string s){
	int left = 0;
	int right = s.size() - 1;

	unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};

	while(left<=right){ // since each pointer will traverse the string once - O(n)
		if(vowels.find(s[left]) == vowels.end()){ // s[left] is not a vowel
			left++;
		}else if(vowels.find(s[right]) == vowels.end()){ // s[right] is not a vowel as well
			right--;
		}else{ // both are vowels
			swap(s[left],s[right]); 
			left++; right--;
		}
	}

	return s;

}

int main(){
	string s1 = "Uber Career Prep";
	string s2 = "xyz";
	string s3 = "flamingo";
	cout << reverseVowels(s1) << endl;
	cout << reverseVowels(s2) << endl;
	cout << reverseVowels(s3);

	return 0;
}


//Learnings:
//1) Always check for infinite loop in while condition
//2) Don't forget to update the pointers in while loop - did so in mock interview also

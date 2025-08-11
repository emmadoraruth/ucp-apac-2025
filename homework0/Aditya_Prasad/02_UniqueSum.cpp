// int n = nums.size()
// T.C = O(n) because we're traversing the array once and each unordered_set operation is O(1) on average.
// M.C = O(n) because we're storing at max n elements.
// Time Taken : 5 min


#include <bits/stdc++.h>
using namespace std;

int uniqueSum(vector<int> nums){
	unordered_set<int> unique;
	int sum = 0;

	for(int num : nums){
		unique.insert(num);
	}

	for(int u : unique){
		sum += u;
	}

	return sum;
}

int main() {

	vector<int> tC1 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
	vector<int> tC3 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
	
	cout << uniqueSum(tC1) << endl;
	cout << uniqueSum(tC3) << endl;
	
	return 0;
}


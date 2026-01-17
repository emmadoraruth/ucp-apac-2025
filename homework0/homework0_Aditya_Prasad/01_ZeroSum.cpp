// int n = nums.size()
// T.C = O(n) because we're traversing the array once and each unordered_set operation is O(1) on average.
// M.C = O(n) because we're storing at max n elements.
// Time Taken : 25 min 


#include <bits/stdc++.h>
using namespace std;

int zeroSum(vector<int> nums){
	unordered_set<int> seen;
	int count = 0;

	for(int num : nums){
		if(seen.find(-1*num)!=seen.end()){
			count++;
			seen.erase(-1*num); 
		}else{
			seen.insert(num);
		}
	}

	return count;
}

int zeroSumFollowUp(vector<int> nums){

	unordered_set<int> seen;
	unordered_map<int,int> mp;
	int count = 0;
	for(int num : nums){
		mp[num]++;
	}
	for(int num : nums){
		if(seen.find(-1*num)!=seen.end() && num!=0){
			count += mp[num]*mp[-num];
			mp[num] = 0;
		}
		seen.insert(num);
	}

	count += mp[0]/2; //handling edge case of 0

	return count;
}

int main() {
	vector<int> tC1 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
	vector<int> tC2 = {1, 10, 8, -2, 2, 5, 7, 2, -2, -1};
	vector<int> tC3 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
	vector<int> tC4 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 0};
	cout << zeroSum(tC1) << endl;
	cout << zeroSum(tC2) << endl;
	cout << zeroSum(tC3) << endl;
	cout << zeroSum(tC4) << endl;

	cout << "Follow Up:" << endl;

	cout << zeroSumFollowUp(tC1) << endl;
	cout << zeroSumFollowUp(tC2) << endl;
	cout << zeroSumFollowUp(tC3) << endl;
	cout << zeroSumFollowUp(tC4);
	return 0;
}



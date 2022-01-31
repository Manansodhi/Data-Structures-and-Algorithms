/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

*/

#include<bits/stdc++.h>
using namespace std;


/*
 Naive Approach (Brute Force)
 Time Complexity: O(N2)
 Space Complexity: O(1)
*/

vector<int> TwoSum(vector<int>& nums, int target) {
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = i + 1; j < nums.size(); ++j) {
			if (nums[i] + nums[j] == target) {
				res.emplace_back(i);
				res.emplace_back(j);
				break;
			}
		}
		if (res.size() == 2)
			break;
	}
	return res;
}


/*
Hashing (Most efficient)
Time Complexity: O(N)
Space Complexity: O(N)
*/


vector<int> TwoSum(vector<int>& nums, int target) {

	vector<int> res;
	unordered_map<int, int> mp;

	for (int i = 0; i < nums.size(); ++i) {

		if (mp.find(target - nums[i]) != mp.end()) {

			res.emplace_back(i);
			res.emplace_back(mp[target - nums[i]]);
			return res;
		}

		mp[nums[i]] = i;
	}

	return res;
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	while (t--) {
		int arr[size];
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
		int target;
		cin >> target;

		vector<int> ans = TwoSum(arr, target);
		for (auto i = ans.begin(); i != ans.end(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
		delete[] arr;
	}
	return 0;
}
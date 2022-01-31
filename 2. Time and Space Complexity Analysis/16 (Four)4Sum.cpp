/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include<bits/stdc++.h>
using namespace std;

/*
Using 3 pointers and Binary Search
Time Complexity: O(N log N + N³ logN)
Reason: Sorting the array takes N log N and three nested loops will be taking N³ and for binary search, it takes another log N.
Space Complexity: O(M * 4), where M is the number of quads
**/

vector<vector<int>> FourSum(vector<int>& nums, int target) {
	int n =  nums.size();
	sort(nums.begin(), nums.end());

	set<vector<int>> sv;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int x = (long long) target - (long long) nums[i] - (long long) nums[j] - (long long) nums[k];

				if(binary_search(nums.begin()+k+1,nums.end(),x)){
					vector<int> v;
					v.emplace_back(nums[i]);
					v.emplace_back(nums[j]);
					v.emplace_back(nums[k]);
					v.emplace_back(x);
					sort(v.begin(),v.end());
					sv.insert(v);
				}
			}
		}
	}

	vector<vector<int>> res(sv.begin(),sv.end());
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
		vector<int>v;
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
		int target;
		cin >> target;

		vector<vector<int>> ans = FourSum(arr, target);
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}

		cout << endl;
		delete[] arr;
	}
	return 0;
}
/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

Example 1:
Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]

Output: 2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

Example 2:
Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]

Output: 1

Constraints:
n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

*/

#include<bits/stdc++.h>
using namespace std;

/*
Time:- O(N^2)
Space:- O(N)
*/

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
	int count = 0;
	unordered_map<int, int>mp;
	for (auto a : nums1) {
		for (auto b : nums2) {
			int idx = a + b;
			mp[idx]++;
		}
	}
	for (auto c : nums3) {
		for (auto d : nums4) {
			int idx = -1 * (c + d);
			if (mp[idx]) {
				count += mp[idx];
			}
		}
	}
	return count;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (t--) {
		int size;
		cin >> size;
		int arr[size];
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}

		vector<int> ans = Longest_Consecutive_Sequence(arr, size);
		for (auto i = ans.begin(); i != ans.end(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
		delete[] arr;
	}



	return 0;
}
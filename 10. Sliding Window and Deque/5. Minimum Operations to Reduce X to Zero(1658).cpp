/*
1658. Minimum Operations to Reduce X to Zero

You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.


Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:
Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109
*/

class Solution {
public:
	int minOperations(vector<int>& nums, int x) {
		int sum = 0, n = nums.size();
		for (int i : nums) sum += i;
		int target = sum - x;
		int windowSum = 0, ans = 0;
		int start = 0;
		bool found = false;
		for (int end = 0; end < n; end++) {
			windowSum += nums[end];

			//shrinking our window
			while (start <= end && windowSum >= target) {
				windowSum -= nums[end];
				start++;
			}
			if (windowSum == target) {
				found == true;
				ans = max(ans, end - start + 1);
			}
		}
		return found ? n - ans : -1;
	}
};
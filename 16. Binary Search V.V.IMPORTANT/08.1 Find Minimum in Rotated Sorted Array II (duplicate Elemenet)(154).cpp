/*154. Find Minimum in Rotated Sorted Array II

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:
[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
You must decrease the overall operation steps as much as possible.


Example 1:
Input: nums = [1,3,5]
Output: 1

Example 2:
Input: nums = [2,2,2,0,1]
Output: 0

Constraints:
n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums is sorted and rotated between 1 and n times.

Follow up: This problem is similar to Find Minimum in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?

worst case TC- O(N)
avg cas TC- O(logN)
 */


class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		int start = 0, end = n - 1;
		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] < nums[end]) {
				end = mid;
			}
			else if (nums[mid] > nums[end]) {
				start = mid + 1;
			}
			else {//nums[mid]==nums[end]
				//OR
				// if(start!=0 && nums[start] >= nums[start-1])
				// 	end--;
				// else
				// 	return nums[end];
				end--;
			}
		}
		return nums[start];
	}
};
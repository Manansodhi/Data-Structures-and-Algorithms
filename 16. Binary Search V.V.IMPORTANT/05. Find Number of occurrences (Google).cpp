/*Google | Find the number of occurrences of an element in a sorted array

Given a sorted array of n elements, possibly with duplicates, find the number of occurrences of the target element.

Example 1:

Input: arr = [4, 4, 8, 8, 8, 15, 16, 23, 23, 42], target = 8
Output: 3
Example 2:

Input: arr = [3, 5, 5, 5, 5, 7, 8, 8], target = 6
Output: 0
Example 3:

Input: arr = [3, 5, 5, 5, 5, 7, 8, 8], target = 5
Output: 4
Expected O(logn) time solution.

*/


class Solution {
public:
	int F_Occ(vector<int>&nums, int target) {
		int start = 0, end = nums.size() - 1, res = -1;
		while (start <= end) {
			int mid = start + ((end - start) / 2);
			if (nums[mid] == target) {
				res = mid;
				end = mid - 1;
			}
			else if (nums[mid] > target) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		return res;
	}

	int L_Occ(vector<int>&nums, int target) {
		int start = 0, end = nums.size() - 1, res = -1;
		while (start <= end) {
			int mid = start + ((end - start) / 2);
			if (nums[mid] == target) {
				res = mid;
				start = mid + 1;
			}
			else if (nums[mid] > target) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		return res;
	}
	int NumberOccurence(vector<int>& nums, int target) {
		int count;
		int F_Occurence = F_Occ(nums, target);
		int L_Occurence = L_Occ(nums, target);
		count = L_Occurence - F_Occurence + 1;
		return count;
	}
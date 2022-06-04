/*
35. Search Insert Position/11. Return Index of Elemnet if it is present if not present then return idx at which it should be present

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.


Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int n = nums.size(), start = 0;
    int end = n - 1;
    int res;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[mid] >= target) {
        //res=mid;
        end = mid - 1;
      }
      else if (nums[mid] <= target) {
        res = mid + 1;
        start = mid + 1;
      }
    }
    return res;
  }
};
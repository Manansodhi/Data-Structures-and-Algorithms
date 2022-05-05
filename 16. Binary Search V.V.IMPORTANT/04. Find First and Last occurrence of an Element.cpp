/*
Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.


Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
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
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>res;
    int F_Occurence = F_Occ(nums, target);
    int L_Occurence = L_Occ(nums, target);
    res.push_back(F_Occurence);
    res.push_back(L_Occurence);
    return res;
  }
};
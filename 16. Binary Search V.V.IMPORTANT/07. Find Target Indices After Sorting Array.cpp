/*
 Find Target Indices After Sorting Array

You are given a 0-indexed integer array nums and a target element target.
A target index is an index i such that nums[i] == target.
Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

Example 1:
Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.

Example 2:
Input: nums = [1,2,5,2,3], target = 3
Output: [3]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 3 is 3.

Example 3:
Input: nums = [1,2,5,2,3], target = 5
Output: [4]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 5 is 4.


Constraints:
1 <= nums.length <= 100
1 <= nums[i], target <= 100
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


  vector<int> targetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int>res;
    int F_Occurence = F_Occ(nums, target);
    int L_Occurence = L_Occ(nums, target);
    if (F_Occurence != -1) {
      for (int i = F_Occurence; i <= L_Occurence; i++) {
        res.push_back(i);
      }
    }
    return res;
  }
};
/*
Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
 

Constraints:-
1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
*/



class Solution {
public:
  int findMinIdx(vector<int>& arr){
    int n=arr.size();
    int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		int prev = (mid - 1 + n) % n;
		int next = (mid + 1) % n;

		if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
			return mid;
		else if (arr[mid] <= arr[end])
			end = mid - 1;
		else if (arr[mid] >= arr[start])
			start = mid + 1;
	}
	return 0;
  }
  
  int binarySearch(vector<int>& arr,int start, int end,int target){
    while(start<=end){
      int mid=start+(end-start)/2;
      if(arr[mid]==target)
        return mid;
      else if(arr[mid]>=target)
        end=mid-1;
      else
        start=mid+1;
    }
    return -1; 
  }
  
    int search(vector<int>& nums, int target) {
      int noOfRotation=findMinIdx(nums);
      int eleIndex=binarySearch(nums, noOfRotation, nums.size() - 1, target);
      if(eleIndex>=0){
        return eleIndex;
      }
      return binarySearch(nums, 0, noOfRotation - 1, target);
    }

};
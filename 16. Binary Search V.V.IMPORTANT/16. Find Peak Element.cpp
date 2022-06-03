/*
162. Find Peak Element

A peak element is an element that is strictly greater than its neighbors.
Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞.
You must write an algorithm that runs in O(log n) time.

 
Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 
Constraints:
1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.
*/

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
      int Size=arr.size();
      int start=0,end=Size-1;
      while(start<=end){
        int mid=start+(end-start)/2;
        if(mid>0 && mid<Size-1){
          if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
          }
          
          else if(arr[mid]< arr[mid-1]){
            end=mid-1;
          }
          else{
            start=mid+1;
          }
        }
        
        else if(mid==0){
          if(arr[0]>arr[1]){
            return 0;
          }
          else{
            return 1;
          }
        }
        
        else if(mid==Size-1){
          if(arr[Size-1]>arr[Size-2])
            return Size-1;
          else
            return Size-2;
        }
        else
          return 0;
      } 
      return -1;
    }
};




class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    
        int n = nums.size();
        if(n == 1) return 0; // single element
    // check if 0th/n-1th index is the peak element
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
    
    // search in the remaining array
        int start = 1;
        int end = n-2;
        
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] < nums[mid-1]) end = mid - 1;
            else if(nums[mid] < nums[mid+1]) start = mid + 1;
        }
        return -1; // dummy return statement
    }
};
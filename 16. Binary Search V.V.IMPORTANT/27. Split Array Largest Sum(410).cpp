/*
410. Split Array Largest Sum

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

 
Example 1:
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], m = 2
Output: 9

Example 3:
Input: nums = [1,4,4], m = 3
Output: 4
 
Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= m <= min(50, nums.length)
*/


class Solution {
public:
  bool numberOfSubarraybyKeepingLimit(vector<int>& nums, int n, int limit, int m){
    int cnt=1,sum=0;
    for(int i=0;i<n;i++){
      if(nums[i]>limit){
        return false;
      }
      if(sum+nums[i]>limit){
        cnt++;
        sum=nums[i];
      }
      else{
        sum+=nums[i];
      }
    }
    return cnt<=m;
  }
  
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
      int low=*max_element(nums.begin(),nums.end());\
        int high=0;
      for(int i=0;i<n;i++){
        high+=nums[i];
      }
      int ans= high;
      while(low<=high){
        int mid=low+(high-low)/2;
        if(numberOfSubarraybyKeepingLimit(nums,n,mid,m)==false){
          low=mid+1;
        }
        else{
          ans=mid;
          high=mid-1;
        }
      }
      return ans;
    }
};
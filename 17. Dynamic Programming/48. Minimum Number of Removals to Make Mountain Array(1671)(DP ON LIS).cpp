/*
1671. Minimum Number of Removals to Make Mountain Array

You may recall that an array arr is a mountain array if and only if:
arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums, return the minimum number of elements to remove to 
make nums a mountain array.


Example 1:
Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.

Example 2:
Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
 
Constraints:
3 <= nums.length <= 1000
1 <= nums[i] <= 109
It is guaranteed that you can make a mountain array out of nums.
*/

class Solution {
public:
    
  

int longestBitonicSequence(vector<int>& arr, int n) {
      vector<int> dp1(n,1);
     for(int idx=0;idx<=n-1;idx++){
       for(int prev=0;prev<idx;prev++){
         if(arr[prev]<arr[idx] && 1+dp1[prev] > dp1[idx]){
           dp1[idx] = 1+dp1[prev];
         }
       }
     }
    
    vector<int> dp2(n,1);
     for(int idx=n-1;idx>=0;idx--){
       for(int prev=n-1;prev>idx;prev--){
         if(arr[prev]<arr[idx]&& 1+dp2[prev] > dp2[idx]){
           dp2[idx] = 1+dp2[prev];
         }
       }
     }
    
    int maxi = -1;
    for(int i=0;i<n;i++){
      if(dp1[i]==1 || dp2[i]==1)continue;
      //see dp1 says that longest increasing subseq from left to that element
            // and if the value is 1 that simply means there are no elements to its left
            //the same way with dp2 which says about the longest increasing subseq from right to left
            // and if the value is 1 that simply means there are no elements to its right 
            // the value is 1 coz we are counting that particular element as well 
        maxi = max(maxi,dp1[i]+dp2[i]-1);
    }
    return maxi;
    
}
  int minimumMountainRemovals(vector<int>& nums) {
      int n = nums.size();
      int m = longestBitonicSequence(nums,n);
      return n-m;
    }
};
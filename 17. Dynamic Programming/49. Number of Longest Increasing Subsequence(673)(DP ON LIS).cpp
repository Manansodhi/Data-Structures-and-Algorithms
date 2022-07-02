/*
673. Number of Longest Increasing Subsequence

Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.

Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
 
Constraints:
1 <= nums.length <= 2000
-106 <= nums[i] <= 106
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
      int n = arr.size();
      vector<int> dp(n,1),count(n,1);
       int maxi=1;
       for(int idx=0;idx<=n-1;idx++){ 
         for(int prev=0;prev<=idx-1;prev++){
           if(arr[prev]<arr[idx] && 1+dp[prev]>dp[idx]){
             dp[idx] = 1+dp[prev];
               count[idx]=count[prev];
           }
             else if(arr[prev]<arr[idx] && 1+dp[prev]==dp[idx]){
                 count[idx] += count[prev];
             }
         }
           maxi = max(maxi,dp[idx]);
       }
      int NoLIS=0;
      for(int i=0;i<n;i++){
          if(dp[i] == maxi)
              NoLIS+=count[i];
      }
      return NoLIS;
    }
};

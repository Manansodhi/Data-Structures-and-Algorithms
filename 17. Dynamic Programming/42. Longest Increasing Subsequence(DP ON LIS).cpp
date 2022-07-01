/*
300. Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements 
without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of 
the array [0,3,1,6,2,2,7].

 
Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3
Input: nums = [7,7,7,7,7,7,7]
Output: 1
 
Constraints:
1 <= nums.length <= 2500
-104 <= nums[i] <= 104
*/

class Solution {
public:
  
 //RECURSIVE
  int f(int idx, int prevIdx, vector<int> &arr){
    
    int n = arr.size();
    //base case
    if(idx==n){
      return 0;
    }
    
    int len;
    
    // does NOT include element in LIS
    len =0+f(idx+1,prevIdx,arr);
    
    //take Elemenet in LIS
    if(prevIdx == -1 || arr[idx] > arr[prevIdx]){
      len = max(len, 1+f(idx+1, idx,arr));
    }
    
    return len;
  }
  
    int lengthOfLIS(vector<int>& arr) {
        return f(0, -1, arr);
    }
  
  
  //MEMOIZATION
   int f(int idx, int prevIdx, vector<int> &arr, vector<vector<int>> &dp){
    
    int n = arr.size();
    //base case
    if(idx==n){
      return 0;
    }
     
     if(dp[idx][prevIdx+1] != -1)
       return dp[idx][prevIdx+1];
    
    int len;
    
    // does NOT include element in LIS
    len =0+f(idx+1,prevIdx,arr,dp);
    
    //take Elemenet in LIS
    if(prevIdx == -1 || arr[idx] > arr[prevIdx]){
      len = max(len, 1+f(idx+1, idx,arr,dp));
    }
    
    return dp[idx][prevIdx+1] = len;
  }
  
    int lengthOfLIS(vector<int>& arr) {
      int n = arr.size();
      vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0, -1, arr, dp);
    }
  
  
    //TABULATION
  
    int lengthOfLIS(vector<int>& arr) {
      int n = arr.size();
      vector<vector<int>> dp(n+1,vector<int>(n+1,0));
      
      for(int idx=n-1;idx>=0;idx--){
        for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--){
           int len;
    
          // does NOT include element in LIS
          len =0+dp[idx+1][prevIdx+1];

          //take Elemenet in LIS
          if(prevIdx == -1 || arr[idx] > arr[prevIdx]){
            //second parameter of dp[][..+1] becoz od right shifting of coordinates
            len = max(len, 1+dp[idx+1][idx+1]);
            //second parameter of dp[][..+1] becoz od right shifting of coordinates
          }
          dp[idx][prevIdx+1] = len;
        }
      }
        return dp[0][-1+1];
    }
  
  
  //SPACE OPTIMIZATION
   int lengthOfLIS(vector<int>& arr) {
      int n = arr.size();
      vector<int> next(n+1,0), curr(n+1,0);
      
      for(int idx=n-1;idx>=0;idx--){
        for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--){
           int len;
    
          // does NOT include element in LIS
          len =0+next[prevIdx+1];

          //take Elemenet in LIS
          if(prevIdx == -1 || arr[idx] > arr[prevIdx]){
            //second parameter of dp[][..+1] becoz od right shifting of coordinates
            len = max(len, 1+next[idx+1]);
            //second parameter of dp[][..+1] becoz od right shifting of coordinates
          }
          curr[prevIdx+1] = len;
        }
        next = curr;
      }
        return next[-1+1];
    }
  
  
//ALGORITHMIC APPROCH
   int lengthOfLIS(vector<int>& arr) {
      int n = arr.size();
      vector<int> dp(n,1);
     int maxi=1;
     for(int idx=0;idx<=n-1;idx++){
       for(int prev=0;prev<=idx-1;prev++){
         if(arr[prev]<arr[idx]){
           dp[idx] = max(dp[idx], 1+dp[prev]);
         }
       }
       maxi=max(maxi,dp[idx]);
     }
     return maxi;
    }
  
  
};

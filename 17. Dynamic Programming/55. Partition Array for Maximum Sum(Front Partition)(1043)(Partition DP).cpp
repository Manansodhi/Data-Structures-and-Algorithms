/*
1043. Partition Array for Maximum Sum

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After 
partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer 
fits in a 32-bit integer.

 
Example 1:
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Example 2:
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

Example 3:
Input: arr = [1], k = 1
Output: 1
 
Constraints: 
1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length
*/


class Solution {
public:
  
  //RECURSION
  
  int f(int idx, int k, vector<int> &arr){
    int n = arr.size();
    if(idx==n)
      return 0;
    
    int maxAns=-1e9,len=0,maxi=-1e9;
    for(int j=idx; j<min(n,idx+k); j++){
      len++;
      maxi=max(maxi,arr[j]);
      int sum = len*maxi + f(j+1,k,arr);
      maxAns = max(maxAns,sum);
    }
    return maxAns;
  }
  
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int n = arr.size();
      return f(0,k,arr);
    }
  
  //MEMOIZATION
    int f(int idx, int k, vector<int> &arr, vector<int> &dp){
    int n = arr.size();
    if(idx==n)
      return 0;
    
    if(dp[idx] != -1)
      return dp[idx];
      
    int maxAns=-1e9,len=0,maxi=-1e9;
    for(int j=idx; j<min(n,idx+k); j++){
      len++;
      maxi=max(maxi,arr[j]);
      int sum = len*maxi + f(j+1,k,arr,dp);
      maxAns = max(maxAns,sum);
    }
    return dp[idx] = maxAns;
  }
  
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int n = arr.size();
      vector<int> dp(n,-1);
      return f(0,k,arr,dp);
    }
  
  //TABULATION

  
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int n = arr.size();
      vector<int> dp(n+1,0);
      
      dp[n]=0; 
      for(int idx=n-1;idx>=0;idx--){
        int maxAns=-1e9,len=0,maxi=-1e9;
        for(int j=idx; j<min(n,idx+k); j++){
          len++;
          maxi=max(maxi,arr[j]);
          int sum = len*maxi + dp[j+1];
          maxAns = max(maxAns,sum);
        }
         dp[idx] = maxAns;
      }
      return dp[0];
    }
};
/*
322. Coin Change

You are given an integer array coins representing coins of different denominations and an 
integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of 
money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

 
Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0
 

Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

*/

class Solution {
public:
  
//RECURSION  TLE TLE
  int f(int idx, int target, vector<int> &coins){
    //base case
    if(idx==0){
      if(target%coins[idx] == 0){
        return target/coins[idx];
      }
      else{
        return 1e8;
      }
    }
    
    int notTake = 0+f(idx-1, target, coins);
    int take = INT_MAX;
    if(target>=coins[idx]){
      take = 1 + f(idx,target-coins[idx], coins);
    }
    return min(notTake, take);
  }
  
    int coinChange(vector<int>& coins, int target) {
     int n = coins.size();
      int ans = f(n-1, target, coins); 
      if(ans>=1e8)
        return -1;
      else
        return ans;
    }
  
  
  //MEMOIZATION
  
  int f(int idx, int target, vector<int> &coins, vector<vector<int>> &dp){
    //base case
    if(idx==0){
      if(target%coins[idx] == 0){
        return target/coins[idx];
      }
      else{
        return 1e8;
      }
    }
    
    if(dp[idx][target] != -1){
      return dp[idx][target];
    }
    
    int notTake = 0+f(idx-1, target, coins, dp);
    int take = INT_MAX;
    if(target>=coins[idx]){
      take = 1 + f(idx,target-coins[idx], coins, dp);
    }
    return dp[idx][target] = min(notTake, take);
  }
  
    int coinChange(vector<int>& coins, int target) {
     int n = coins.size();
      vector<vector<int>> dp(n,vector<int>(target+1, -1));
      int ans = f(n-1, target, coins, dp); 
      if(ans>=1e8)
        return -1;
      else
        return ans;
    }
  
    //TABULATION
  
    int coinChange(vector<int>& coins, int target) {
     int n = coins.size();
      vector<vector<int>> dp(n,vector<int>(target+1, 0));
      
      //BASE CASE
      for(int t=0;t<=target;t++){
        if(t%coins[0] == 0)
          dp[0][t] = t/coins[0];
        else
          dp[0][t] = 1e8;
      }
      
      for(int idx=1;idx<n;idx++){
        for(int t=0;t<=target;t++){
          int notTake = 0 + dp[idx-1][t];
          int take = INT_MAX;
          if(t>=coins[idx]){
            take = 1 + dp[idx][t-coins[idx]];
          }
           dp[idx][t] = min(notTake, take);
        }
      }
      int ans = dp[n-1][target]; 
      if(ans>=1e8)
        return -1;
      else
        return ans;
    }
  
  
    //SPACE OPTIMIZATION
  
    int coinChange(vector<int>& coins, int target) {
     int n = coins.size();
      vector<int>prev(target+1, 0), curr(target+1, 0);
      
      //BASE CASE
      for(int t=0;t<=target;t++){
        if(t%coins[0] == 0)
          prev[t] = t/coins[0];
        else
          prev[t] = 1e8;
      }
      
      for(int idx=1;idx<n;idx++){
        for(int t=0;t<=target;t++){
          int notTake = 0 + prev[t];
          int take = INT_MAX;
          if(t>=coins[idx]){
            take = 1 + curr[t-coins[idx]];
          }
           curr[t] = min(notTake, take);
        }
        prev = curr;
      }
      int ans = prev[target]; 
      if(ans>=1e8)
        return -1;
      else
        return ans;
    }
  
  
};
/*
518. Coin Change 2

You are given an integer array coins representing coins of different denominations and an 
integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot 
be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.

 
Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
Input: amount = 10, coins = [10]
Output: 1
 
Constraints:
1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/

class Solution {
public:
  
  //RECRSION TLE TLE
  int f(int idx, int target, vector<int> &coins){
    // base case
    if(idx==0){
      if(target%coins[idx] == 0)
        return 1;
      else
        return 0;
    }
    
    int notTake = f(idx-1, target, coins);
    int take=0;
    if(coins[idx]<=target){
      take = f(idx, target-coins[idx], coins);
    }
    return take+notTake;
  }
    int change(int target, vector<int>& coins) {
        int n = coins.size();
      return f(n-1, target, coins);
    }
  
  //Memoization
  int f(int idx, int target, vector<int> &coins, vector<vector<int>> &dp){
    // base case
    if(idx==0){
      if(target%coins[idx] == 0)
        return 1;
      else
        return 0;
    }
    if(dp[idx][target] != -1){
      return dp[idx][target];
    }
    
    int notTake = f(idx-1, target, coins, dp);
    int take=0;
    if(coins[idx]<=target){
      take = f(idx, target-coins[idx], coins, dp);
    }
    return dp[idx][target] = take+notTake;
  }
    int change(int target, vector<int>& coins) {
        int n = coins.size();
      vector<vector<int>> dp(n, vector<int>(target+1, -1));
      return f(n-1, target, coins, dp);
    }
  
  //Tabulation
   
    int change(int target, vector<int>& coins) {
        int n = coins.size();
      vector<vector<int>> dp(n, vector<int>(target+1, 0));
      
      //base case
      for(int t=0; t<=target; t++){
        dp[0][t] = (t%coins[0] == 0);
      }
      
      for(int idx=1; idx<=n-1; idx++){
        for(int t=0; t<=target; t++){
              int notTake = dp[idx-1][t];
              int take=0;
              if(coins[idx]<=t){
                take = dp[idx][t-coins[idx]];
              }
             dp[idx][t] = take+notTake;
        }
      }
      return dp[n-1][target];
    }
  
  
  //Space Optimization
  int change(int target, vector<int>& coins) {
        int n = coins.size();
      vector<int>prev(target+1,0), curr(target+1, 0);
      
      //base case
      for(int t=0; t<=target; t++){
        prev[t] = (t%coins[0] == 0);
      }
      
      for(int idx=1; idx<=n-1; idx++){
        for(int t=0; t<=target; t++){
              int notTake = prev[t];
              int take=0;
              if(coins[idx]<=t){
                take = curr[t-coins[idx]];
              }
             curr[t] = take+notTake;
        }
        prev=curr;
      }
      return prev[target];
    }
};
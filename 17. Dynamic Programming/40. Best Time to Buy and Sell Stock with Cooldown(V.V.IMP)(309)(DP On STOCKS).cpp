/*
309. Best Time to Buy and Sell Stock with Cooldown
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy 
one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before 
you buy again).

 
Example 1
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
Input: prices = [1]
Output: 0
 
Constraints:
1 <= prices.length <= 5000
0 <= prices[i] <= 1000

*/


class Solution {
public:
  
  //RECURSION TLE TLE
    int f(int idx, int buy, vector<int> &prices){
      int n = prices.size();
      //base case
      if(idx>=n)
        return 0;
      
      //explore all possibilities
      if(buy){
        return max(-prices[idx]+f(idx+1,0,prices), 0+f(idx+1,1,prices));
      }
      else{
        return max(prices[idx]+f(idx+2,1,prices), 0+f(idx+1,0,prices));
      }
    }
  
  
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      return f(0,1,prices);
    }
  
  
  //MEMOIZATION
      int f(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp){
      int n = prices.size();
      //base case
      if(idx>=n)
        return 0;
        
        if(dp[idx][buy] != -1){
          return dp[idx][buy];
        }
      
      //explore all possibilities
      if(buy){
        return dp[idx][buy] = max(-prices[idx]+f(idx+1,0,prices,dp), 0+f(idx+1,1,prices,dp));
      }
      else{
        return dp[idx][buy] = max(prices[idx]+f(idx+2,1,prices,dp), 0+f(idx+1,0,prices,dp));
      }
    }
  
  
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<vector<int>> dp(n,vector<int>(2,-1));
      return f(0,1,prices,dp);
    }
  
  
  //TABULATION
  
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<vector<int>> dp(n+2,vector<int>(2,0));
      
      //No need to write base case becoz dp[][] is already intialized with 0
      
      for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
          if(buy){
             dp[idx][buy] = max(-prices[idx]+dp[idx+1][0], 0+dp[idx+1][1]);
          }
          else{
             dp[idx][buy] = max(prices[idx]+dp[idx+2][1], 0+dp[idx+1][0]);
          }
        }
      }
      
      return dp[0][1];
    }
  
  //SPACE OPTIMIZATION 1
    
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<vector<int>> dp(n+2,vector<int>(2,0));
      
      //No need to write base case becoz dp[][] is already intialized with 0
      
      for(int idx=n-1;idx>=0;idx--){
       
             dp[idx][1] = max(-prices[idx]+dp[idx+1][0], 0+dp[idx+1][1]);
         
          
             dp[idx][0] = max(prices[idx]+dp[idx+2][1], 0+dp[idx+1][0]);
          
        
      }
      
      return dp[0][1];
    }
  
  
  //SPACE OPTIMIZATION 2
    
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<int>front2(2,0);
      vector<int>front1(2,0);
      vector<int>curr(2,0);
      
      //No need to write base case becoz dp[][] is already intialized with 0
      
      for(int idx=n-1;idx>=0;idx--){
       
             curr[1] = max(-prices[idx]+front1[0], 0+front1[1]);
         
          
             curr[0] = max(prices[idx]+front2[1], 0+front1[0]);
          
        front2 = front1;
        front1 = curr;
      }
      
      
      return curr[1];
    }
};
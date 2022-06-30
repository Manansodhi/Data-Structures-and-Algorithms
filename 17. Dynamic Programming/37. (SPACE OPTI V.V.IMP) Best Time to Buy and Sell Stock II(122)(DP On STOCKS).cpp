/*
122. Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the 
stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7

Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4

Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the 
maximum profit of 0.
 
Constraints:
1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/

class Solution {
public:
  
 //RECURSION
  int f(int idx, bool buy, vector<int>& prices){
    int n = prices.size();
    
    //base case
    if(idx == n)
      return 0;
    
    //explore all passibilities
    int profit = INT_MIN;
    if(buy){
      profit = max(-prices[idx]+f(idx+1,0,prices), 0+f(idx+1,1,prices));
    }
    else{
      profit = max(prices[idx]+f(idx+1,1,prices), 0+f(idx+1,0,prices));
    }
    return profit;
    
  }
  
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
      return f(0, 1, prices);
    }
  
  
  //MEMOIZATION
   int f(int idx, bool buy, vector<int>& prices, vector<vector<int>> dp){
    int n = prices.size();
    
    //base case
    if(idx == n)
      return 0;
     
     if(dp[idx][buy] != -1)
       return dp[idx][buy];
    
    //explore all passibilities
    int profit = INT_MIN;
    if(buy){
      profit = max(-prices[idx]+f(idx+1,0,prices,dp), 0+f(idx+1,1,prices,dp));
    }
    else{
      profit = max(prices[idx]+f(idx+1,1,prices,dp), 0+f(idx+1,0,prices,dp));
    }
    return dp[idx][buy] = profit;
    
  }
  
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
      vector<vector<int>> dp(n,vector<int>(2,-1));
      return f(0, 1, prices, dp);
    }
  
  //TABULATION
  
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
      vector<vector<int>> dp(n+1,vector<int>(2,0));
      //base case
      dp[n][0] = dp[n][1] = 0;
      
      for(int idx = n-1; idx>=0; idx--){
        for(int buy = 0; buy<=1; buy++){
          int profit = INT_MIN;
          if(buy){
            profit = max(-prices[idx]+dp[idx+1][0], 0+dp[idx+1][1]);
          }
          else{
            profit = max(prices[idx]+dp[idx+1][1], 0+dp[idx+1][0]);
          }
           dp[idx][buy] = profit;
        }
      }
      
      return dp[0][1];
    }
  
  //SPACE OPTIMIZIATION
      int maxProfit(vector<int>& prices) {
        int n = prices.size();
      vector<int> ahead(2,0), curr(2,0); 
      //base case
      ahead[0] = ahead[1] = 0;
      
      for(int idx = n-1; idx>=0; idx--){
        for(int buy = 0; buy<=1; buy++){
          int profit = INT_MIN;
          if(buy){
            profit = max(-prices[idx]+ahead[0], 0+ahead[1]);
          }
          else{
            profit = max(prices[idx]+ahead[1], 0+ahead[0]);
          }
           curr[buy] = profit;
        }
        ahead = curr;
      }
      
      return ahead[1];
    }
  
  
    //SPACE OPTIMIZIATION
      int maxProfit(vector<int>& prices) {
        int n = prices.size();
      //base case
     int  aheadNotBuy ,aheadBuy, currBuy, currNotBuy;
       aheadNotBuy = aheadBuy = 0;
        
      for(int idx = n-1; idx>=0; idx--){
      
          
        currNotBuy = max(prices[idx]+aheadBuy, 0+aheadNotBuy);
            currBuy = max(-prices[idx]+aheadNotBuy, 0+aheadBuy);
            
           
        
        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
      }
      
      return aheadBuy;
    }
  
};
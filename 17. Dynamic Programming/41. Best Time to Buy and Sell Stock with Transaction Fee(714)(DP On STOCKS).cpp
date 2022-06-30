/*
714. Best Time to Buy and Sell Stock with Transaction Fee
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an 
integer fee representing a transaction fee.Find the maximum profit you can achieve. You may complete 
as many transactions as you like, but you need to pay the transaction fee for each transaction.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before 
you buy again).

 
Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2

Output: 8

Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 
Constraints:
1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/


class Solution {
public:
   
   //RECURSION
  int f(int idx, bool buy, vector<int>& prices,fee){
    int n = prices.size();
    
    //base case
    if(idx == n)
      return 0;
    
    //explore all passibilities
    int profit = INT_MIN;
    if(buy){
      profit = max(-prices[idx]-fee+f(idx+1,0,prices,fee), 0+f(idx+1,1,prices,fee));
    }
    else{
      profit = max(prices[idx]+f(idx+1,1,prices,fee), 0+f(idx+1,0,prices,fee));
    }
    return profit;
    
  }
  
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
      return f(0, 1, prices,fee);
    }
  
  
  //MEMOIZATION
   int f(int idx, bool buy, vector<int>& prices,fee, vector<vector<int>> dp){
    int n = prices.size();
    
    //base case
    if(idx == n)
      return 0;
     
     if(dp[idx][buy] != -1)
       return dp[idx][buy];
    
    //explore all passibilities
    int profit = INT_MIN;
    if(buy){
      profit = max(-prices[idx]-fee+f(idx+1,0,prices,fee,dp), 0+f(idx+1,1,prices,fee,dp));
    }
    else{
      profit = max(prices[idx]+f(idx+1,1,prices,fee,dp), 0+f(idx+1,0,prices,fee,dp));
    }
    return dp[idx][buy] = profit;
    
  }
  
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
      vector<vector<int>> dp(n,vector<int>(2,-1));
      return f(0, 1, prices,fee, dp);
    }
  
  //TABULATION
  
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
      vector<vector<int>> dp(n+1,vector<int>(2,0));
      //base case
      dp[n][0] = dp[n][1] = 0;
      
      for(int idx = n-1; idx>=0; idx--){
        for(int buy = 0; buy<=1; buy++){
          int profit = INT_MIN;
          if(buy){
            profit = max(-prices[idx]-fee+dp[idx+1][0], 0+dp[idx+1][1]);
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
      int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
      vector<int> ahead(2,0), curr(2,0); 
      //base case
      ahead[0] = ahead[1] = 0;
      
      for(int idx = n-1; idx>=0; idx--){
        for(int buy = 0; buy<=1; buy++){
          int profit = INT_MIN;
          if(buy){
            profit = max(-prices[idx]-fee+ahead[0], 0+ahead[1]);
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
      int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
      //base case
     int  aheadNotBuy ,aheadBuy, currBuy, currNotBuy;
       aheadNotBuy = aheadBuy = 0;
        
      for(int idx = n-1; idx>=0; idx--){
      
          
        currNotBuy = max(prices[idx]+aheadBuy, 0+aheadNotBuy);
            currBuy = max(-prices[idx]-fee+aheadNotBuy, 0+aheadBuy);
            
           
        
        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
      }
      
      return aheadBuy;
    }
};
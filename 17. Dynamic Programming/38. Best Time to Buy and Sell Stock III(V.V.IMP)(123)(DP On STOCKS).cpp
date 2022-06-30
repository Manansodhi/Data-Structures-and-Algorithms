/*
123. Best Time to Buy and Sell Stock III
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before 
you buy again).

 
Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6

Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4

Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple 
transactions at the same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0

Explanation: In this case, no transaction is done, i.e. max profit = 0.
 
Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

class Solution {
public:
  
    //RECURSIVE TLE TLE
  int f(int idx, int buy, int cap, vector<int> & prices){
    int n = prices.size();
    //base case
    if(cap == 0)
      return 0;
    if(idx == n)
      return 0;
    
    //explore all possibilties
    if(buy)
      return max(-prices[idx]+f(idx+1,0,cap,prices), 0+f(idx+1,1,cap,prices));
    else
      return max(prices[idx]+f(idx+1,1,cap-1,prices), 0+f(idx+1,0,cap,prices));
  }
  

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
      return f(0,1,2,prices);
    }
  
  
  //MEMOIZATION
    int f(int idx, int buy, int cap, vector<int> & prices, vector<vector<vector<int>>> &dp){
    int n = prices.size();
    //base case
    if(cap == 0)
      return 0;
    if(idx == n)
      return 0;
    if(dp[idx][buy][cap] != -1)
      return dp[idx][buy][cap];
        
    
    //explore all possibilties
    if(buy)
      return dp[idx][buy][cap] = max(-prices[idx]+f(idx+1,0,cap,prices,dp), 0+f(idx+1,1,cap,prices,dp));
    else
      return dp[idx][buy][cap] = max(prices[idx]+f(idx+1,1,cap-1,prices,dp), 0+f(idx+1,0,cap,prices,dp));
  }
  
 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
      vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
      return f(0,1,2,prices,dp);
    }
  
  
    //TABULATION
  
 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
      vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
      
      //base case
      for(int idx = 0; idx<=n-1; idx++){
        for(int buy = 0; buy<=1; buy++){
          dp[idx][buy][0] = 0;
        }
      }
      
      for(int buy = 0; buy<=1; buy++){
        for(int cap = 0; cap<=2; cap++){
          dp[n][buy][cap]=0;
        }
      }
        
        //explore all paths
        for(int idx = n-1; idx >= 0; idx--){
          for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){
              if(buy==1)
                 dp[idx][buy][cap] = max(-prices[idx]+dp[idx+1][0][cap], 0+dp[idx+1][1][cap]);
              else
                 dp[idx][buy][cap] = max(prices[idx]+dp[idx+1][1][cap-1], 0+dp[idx+1][0][cap]);
            }
          }
        }
     
      
      return dp[0][1][2];
    }
  
  
  //SPACE OPTIMIZATION
      int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
      
      //base case
      for(int idx = 0; idx<=n-1; idx++){
        for(int buy = 0; buy<=1; buy++){
          after[buy][0] = 0;
        }
      }
      
      for(int buy = 0; buy<=1; buy++){
        for(int cap = 0; cap<=2; cap++){
          after[buy][cap]=0;
        }
      }
        
        //explore all paths
        for(int idx = n-1; idx >= 0; idx--){
          for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){
              if(buy==1)
                 curr[buy][cap] = max(-prices[idx]+after[0][cap], 0+after[1][cap]);
              else
                 curr[buy][cap] = max(prices[idx]+after[1][cap-1], 0+after[0][cap]);
            }
          }
          after = curr;
        }
     
      
      return after[1][2];
    }
  
  int f(int idx, int trans, vector<int> &prices){
    int n =prices.size();
    //base case
    if(idx==n || trans ==4)
      return 0;
    
    if(trans%2 ==0){
      return max(-prices[idx]+f(idx+1, trans+1,prices), 0+f(idx+1,trans,prices));
    }
    else{
      return max(prices[idx]+f(idx+1,trans+1,prices), 0+f(idx+1,trans,prices));
    }
  }
  
  int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(0,0,prices); 
  }
  
  //MEMOIZZATION time O(N*4) space O(N*4)+O(N)
  int f(int idx, int trans, vector<int> &prices, vector<vector<int>> &dp){
    int n =prices.size();
    //base case
    if(idx==n || trans ==4)
      return 0;
    if(dp[idx][trans] != -1)
      return dp[idx][trans];
    
    if(trans%2 ==0){
      return dp[idx][trans] = max(-prices[idx]+f(idx+1, trans+1,prices,dp), 0+f(idx+1,trans,prices,dp));
    }
    else{
      return dp[idx][trans] = max(prices[idx]+f(idx+1,trans+1,prices,dp), 0+f(idx+1,trans,prices,dp));
    }
  }
  
  int maxProfit(vector<int>& prices) {
        int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));
        return f(0,0,prices,dp); 
  }

 //TABULATION time and space both O(N*4)
  int maxProfit(vector<int>& prices) {
        int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(5,0));
    
    //base case
    for(int i =0;i<=4;i++)
      dp[n][i] = 0;
    for(int i=0;i<=n;i++)
      dp[i][4]=0;
    
    
    for(int idx=n-1;idx>=0;idx--){
      for(int trans=3;trans>=0;trans--){
        if(trans%2==0){
          dp[idx][trans] = max(-prices[idx]+dp[idx+1][trans+1], 0+dp[idx+1][trans]); 
        }
        else{
          dp[idx][trans] = max(prices[idx]+dp[idx+1][trans+1], 0+dp[idx+1][trans]);
        }                      
      }
    }
    
    
        return dp[0][0]; 
  }
  
  
  //SPACE OPTIMIZATION
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
       vector<int>ahead(5,0),curr(5,0);
      
    //base case
    for(int i =0;i<=4;i++)
      ahead[i] = 0;
    curr[4]=0;
    
    
    for(int idx=n-1;idx>=0;idx--){
      for(int trans=3;trans>=0;trans--){
        if(trans%2==0){
          curr[trans] = max(-prices[idx]+ahead[trans+1], 0+ahead[trans]); 
        }
        else{
          curr[trans] = max(prices[idx]+ahead[trans+1], 0+ahead[trans]);
        }                      
      }
      ahead = curr;
    }
    
    
        return ahead[0]; 
  }
  
};
  

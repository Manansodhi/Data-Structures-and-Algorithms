/*
188. Best Time to Buy and Sell Stock IV

Share
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, 
and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before 
you buy again).

 
Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on 
day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 
Constraints:
0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/


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
  

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
      return f(0,1,k,prices);
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
  
 
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
      vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
      return f(0,1,k,prices,dp);
    }
  
  
    //TABULATION
  
 
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
      vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
      
      //base case
      for(int idx = 0; idx<=n-1; idx++){
        for(int buy = 0; buy<=1; buy++){
          dp[idx][buy][0] = 0;
        }
      }
      
      for(int buy = 0; buy<=1; buy++){
        for(int cap = 0; cap<=k; cap++){
          dp[n][buy][cap]=0;
        }
      }
        
        //explore all paths
        for(int idx = n-1; idx >= 0; idx--){
          for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= k; cap++){
              if(buy==1)
                 dp[idx][buy][cap] = max(-prices[idx]+dp[idx+1][0][cap], 0+dp[idx+1][1][cap]);
              else
                 dp[idx][buy][cap] = max(prices[idx]+dp[idx+1][1][cap-1], 0+dp[idx+1][0][cap]);
            }
          }
        }
     
      
      return dp[0][1][k];
    }
  
  
  //SPACE OPTIMIZATION
      int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
      
      //base case
      for(int idx = 0; idx<=n-1; idx++){
        for(int buy = 0; buy<=1; buy++){
          after[buy][0] = 0;
        }
      }
      
      for(int buy = 0; buy<=1; buy++){
        for(int cap = 0; cap<=k; cap++){
          after[buy][cap]=0;
        }
      }
        
        //explore all paths
        for(int idx = n-1; idx >= 0; idx--){
          for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= k; cap++){
              if(buy==1)
                 curr[buy][cap] = max(-prices[idx]+after[0][cap], 0+after[1][cap]);
              else
                 curr[buy][cap] = max(prices[idx]+after[1][cap-1], 0+after[0][cap]);
            }
          }
          after = curr;
        }
     
      
      return after[1][k];
    }


//2. APPROCH V.V.V.IMPORTANT
 //RECURSIVE  time O(N*k) space O(N*k)+O(N)
int f(int idx, int trans, vector<int> &prices, int k){
    int n = prices.size();
    if(trans == 2*k || idx==n)
        return 0;
    if(trans%2==0){
        return max(-prices[idx]+f(idx+1,trans+1,prices,k), 0+f(idx+1,trans,prices,k));
    }
    else{
        return max(prices[idx]+f(idx+1,trans+1,prices,k), 0+f(idx+1, trans,prices,k));
    }
        
}

int maximumProfit(vector<int>& prices, int n, int k){
    return f(0,0,prices,k);
    
}

//MEMOIZATION
int f(int idx, int trans, vector<int> &prices, int k,vector<vector<int>> &dp){
    int n = prices.size();
    if(trans == 2*k || idx==n)
        return 0;
    if(dp[idx][trans] != -1)
        return dp[idx][trans];
    
    if(trans%2==0){
        return dp[idx][trans] = max(-prices[idx]+f(idx+1,trans+1,prices,k,dp), 0+f(idx+1,trans,prices,k,dp));
    }
    else{
        return dp[idx][trans] = max(prices[idx]+f(idx+1,trans+1,prices,k,dp), 0+f(idx+1, trans,prices,k,dp));
    }
        
}

int maximumProfit(vector<int>& prices, int n, int k){
    vector<vector<int>> dp(n,vector<int>(2*k,-1));
    return f(0,0,prices,k,dp);
    
}

//TABULATION

int maximumProfit(vector<int>& prices, int n, int k){
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
    
    for(int idx=n-1;idx>=0;idx--){
        for(int trans=2*k-1;trans>=0;trans--){
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

int maximumProfit(vector<int>& prices, int n, int k){
    vector<int> after(2*k+1,0);
    vector<int> curr(2*k+1,0);
    
    for(int idx=n-1;idx>=0;idx--){
        for(int trans=2*k-1;trans>=0;trans--){
            if(trans%2==0){
                 curr[trans] = max(-prices[idx]+after[trans+1], 0+after[trans]);
            }
            else{
                 curr[trans] = max(prices[idx]+after[trans+1], 0+after[trans]);
            }
        }
        after = curr;
    }
    return after[0];
    
}
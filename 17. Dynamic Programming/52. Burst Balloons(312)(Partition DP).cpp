/*
312. Burst Balloons

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented
by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 
goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 
Example 1:
Input: nums = [3,1,5,8]
Output: 167

Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:
Input: nums = [1,5]
Output: 10
 
Constraints:
n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/

class Solution {
public:
  
  //RECURSIVE
  int f(int i, int j, vector<int> &a){
    if(i>j)
      return 0;
    
    int maxi = -1e9;
    for(int idx=i;idx<=j;idx++){
      int cost = a[i-1]*a[idx]*a[j+1] + f(i,idx-1,a) + f(idx+1,j,a);
      maxi = max(maxi,cost);
    }
    return maxi;
  }
  
  
    int maxCoins(vector<int>& a) {
      int n = a.size();
      a.push_back(1);
      a.insert(a.begin(),1);
      return f(1,n,a);
    }
  
  
  //MEMOIZATION
  int f(int i, int j, vector<int> &a, vector<vector<int>> &dp){
    if(i>j)
      return 0;
    
    if(dp[i][j] != -1)
      return dp[i][j];
    
    int maxi = -1e9;
    for(int idx=i;idx<=j;idx++){
      int cost = a[i-1]*a[idx]*a[j+1] + f(i,idx-1,a,dp) + f(idx+1,j,a,dp);
      maxi = max(maxi,cost);
    }
    return dp[i][j] = maxi;
  }
  
  
    int maxCoins(vector<int>& a) {
      int n = a.size();
      a.push_back(1);
      a.insert(a.begin(),1);
      vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
      return f(1,n,a,dp);
    }
  
  
    //TABULATION

  
    int maxCoins(vector<int>& a) {
      int n = a.size();
      a.push_back(1);
      a.insert(a.begin(),1);
      vector<vector<int>> dp(n+2,vector<int>(n+2, 0));
      //n+2 becoz in 3rd inner loop of idx when idx+1 is done and idx=n so it will go out of bound so 
      //that why n+2
      for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
          if(i>j)continue;
          int maxi = -1e9;
          for(int idx=i;idx<=j;idx++){
            int cost = a[i-1]*a[idx]*a[j+1] + dp[i][idx-1] + dp[idx+1][j];
            maxi = max(maxi,cost);
          }
          dp[i][j] = maxi;
        }
      }
      
      return dp[1][n];
    }
};
/*
120. Triangle

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on 
index i on the current row, you may move to either index i or index i + 1 on the next row.

OR

You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to 
reach from the top to the bottom row.
The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
You can move only to the adjacent number of row below each step. For example, if you are at index j 
in row i, then you can move to i or i + 1 index in row j + 1 in each step.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
2
3 4
6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10
 
Constraints:
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 
 */



class Solution {
public:
  //RECURSIVE SOL TLE TLE
//   int f(int i, int j, vector<vector<int>>& triangle, int n){
//     if(i==n-1){
//       return triangle[i][j];
//     }
    
//     int down = triangle[i][j] + f(i+1,j,triangle,n);
//     int diagonal = triangle[i][j] + f(i+1,j+1,triangle,n);
    
//     return min(down,diagonal);
//   }
//     int minimumTotal(vector<vector<int>>& triangle) 
//     {
//         int n=triangle.size();
//         return f(0,0,triangle,n);
//     }
  
  
//   //Memoization
//   int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>> &dp){
//     if(i==n-1){
//       return triangle[i][j];
//     }
    
//     if(dp[i][j] != -1){
//       return dp[i][j];
//     }
    
//     int down = triangle[i][j] + f(i+1,j,triangle,n,dp);
//     int diagonal = triangle[i][j] + f(i+1,j+1,triangle,n,dp);
    
//     return dp[i][j] = min(down,diagonal);
//   }
//     int minimumTotal(vector<vector<int>>& triangle) 
//     {
//         int n=triangle.size();
//       vector<vector<int>>dp(n,vector<int>(n,-1));
//         return f(0,0,triangle,n,dp);
//     }
  
//    //Tabulation
//     int minimumTotal(vector<vector<int>>& triangle) 
//     {
//         int n=triangle.size();
//         vector<vector<int>>dp(n,vector<int>(n,0));
//       //base case
//         for(int j = 0;j<n;j++)
//           dp[n-1][j] = triangle[n-1][j];
      
//       for(int i = n-2; i>=0; i--){
//         for(int j = i; j>=0; j--){
//           int down = triangle[i][j] + dp[i+1][j];
//           int diagonal = triangle[i][j] + dp[i+1][j+1];
          
//           dp[i][j] = min(down,diagonal);
//         }
//       }
//       return dp[0][0];
//     }
  
  //Space Optimization
  
  int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        vector<int>prev(n,0),curr(n,0);
      //base case
        for(int j = 0;j<n;j++)
          prev[j] = triangle[n-1][j];
      
      for(int i = n-2; i>=0; i--){
        for(int j = i; j>=0; j--){
          int down = triangle[i][j] + prev[j];
          int diagonal = triangle[i][j] + prev[j+1];
          
          curr[j] = min(down,diagonal);
        }
        prev=curr;
      }
      return prev[0];
    }
  
  
}
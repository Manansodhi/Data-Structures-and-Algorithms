/*
931. Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is 
either directly below or diagonally left/right. Specifically, the next element from position 
(row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 
Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:


//RECURSIVE TLE TLE
int f(int i, int j, vector<vector<int>> &matrix){
    if(j<0 || j>=matrix[0].size())return -1e9;
    if(i==0)return matrix[0][j];
    
    
    int up = matrix[i][j]+f(i-1,j,matrix);
    int dleft = matrix[i][j]+f(i-1,j-1,matrix);
    int dright = matrix[i][j]+f(i-1,j+1,matrix);
    
    return max(up,max(dleft,dright));
    
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e9;
    for(int j=0;j<m;j++){
        maxi = max(maxi,f(n-1,j,matrix));
    }
    return maxi;
}


//Memoization
int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(j<0 || j>=matrix[0].size())return 1e9;
    if(i==0)return matrix[0][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int up = matrix[i][j]+f(i-1,j,matrix,dp);
    int dleft = matrix[i][j]+f(i-1,j-1,matrix,dp);
    int dright = matrix[i][j]+f(i-1,j+1,matrix,dp);
    
    return dp[i][j] = min(up,min(dleft,dright));
    
}


int minFallingPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int mini = 1e9;
    for(int j=0;j<m;j++){
        mini = min(mini,f(n-1,j,matrix,dp));
    }
    return mini;
}
  
  
//Tabulation
int minFallingPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    //base case
    for(int j=0;j<m;j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up = matrix[i][j]+dp[i-1][j];
            int dleft = matrix[i][j];
                if(j-1>=0)
                    dleft+=dp[i-1][j-1];
            else
                dleft+=1e9;
            int dright = matrix[i][j];
            if(j+1<m)
                dright+=dp[i-1][j+1];
            else
                dright+=1e9;
            
            dp[i][j] = min(up,min(dleft,dright));
        }
    }
    
    int mini = 1e9;
    for(int j=0;j<m;j++){
        mini = min(mini,dp[n-1][j]);
    }
    return mini;
}
  
  
  
//SPACE OPTIMIZATION
int minFallingPathSum(vector<vector<int>> &matrix)
{
    
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m,0), curr(m,0);
    
    //base case
    for(int j=0;j<m;j++){
        prev[j] = matrix[0][j];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up = matrix[i][j]+prev[j];
            int dleft = matrix[i][j];
                if(j-1>=0)
                    dleft+=prev[j-1];
            else
                dleft+=1e9;
            int dright = matrix[i][j];
            if(j+1<m)
                dright+=prev[j+1];
            else
                dright+=1e9;
            
            curr[j] = min(up,min(dleft,dright));
        }
        prev=curr;
    }
    
    int mini = 1e9;
    for(int j=0;j<m;j++){
        mini = min(mini,prev[j]);
    }
    return mini;
}
  
};
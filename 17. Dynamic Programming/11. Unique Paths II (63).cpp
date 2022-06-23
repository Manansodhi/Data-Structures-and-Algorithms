/*
63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner 
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.

 
Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 
Constraints:
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

*/

//Recursive  TLE  TLE
//TIME: O(2^(m*n))
//SPACE: O(pathLength) pathLength = (m-1)+(n-1)

int f(int row, int col, vector<vector<int>> &a){
	if(row == 0 && col == 0)return 1;
	if(row < 0 || col < 0) return 0;
	if(row>=0 && col>=0 && a[row][col]==-1)return 0;
	int up = f(row-1, col, a);
	int left = f(row, col-1, a);

	return up+left;
}

int uniquePaths(int m, int n, vector<vector<int>> &a){
	return f(m-1, n-1, a);
}

//Memiozation
//TIME: O(n*m) maximum number of recursive calls are n*m
//SPACE: O(pathLength) + O(n*m) Recursive stack space --> pathLength = (m-1)+(n-1) 
//and n*m --> for dp[][]array
int f(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &a){
	if(row>=0 && col>=0 && a[row][col]==-1)return 0;
	if(row == 0 && col == 0)return 1;
	if(row < 0 || col < 0) return 0;
	if(dp[row][col] != -1)
		return dp[row][col];
	int up = f(row-1, col, dp, arr);
	int left = f(row, col-1, dp, a);

	return dp[row][col] = up+left;
}

int uniquePaths(int m, int n, vector<vector<int>> &a){
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return f(m-1, n-1, dp, a);
}


//TABULATION
//TIME: O(n*m) Nested for loop
//SPACE: O(n*m) only for dp[][] array and not any for Recursive stack space

int uniquePaths(int m, int n, vector<vector<int>> &a){
	int dp[m][n];
	for(int row = 0; row < m; row++){
		for(int col = 0; col < n; col++){
			if(a[row][col]==-1)
				dp[row][col]=0;
			else if(row==0 && col==0)
				dp[row][col]=1;;
			else{
				int up=0,left=0;
				if(row>0)
					up=dp[row-1][col];
				if(col>0)
					left=dp[row][col-1];
				dp[row][col] = up+left;
			}
		}
	}
	return dp[m-1][n-1];
}


//SPACE OPTIMIZATION
//TIME: O(M*N)  There are two nested loops
//SPACE: O(N) We are using an dummy external array of size ‘N’ to store only one row.

int uniquePaths(int m, int n, vector<vector<int>> &a){
	vector<int> prev(n,0);
	for(int row = 0; row < m; row++){
		//current Row that is being computed
		vector<int>curr(n,0);
		for(int col = 0; col < n; col++){
			if(row>=0 && col>=0 && a[row][col]==-1)
				curr[col]=0;
			else if(row==0 && col==0)//now current row is curr so replace dp[i] with curr
				curr[col]=1;
			else{
				int up=0,left=0;
				if(row>0)  //dp[row-1] is the prev
					up=prev[col];
				if(col>0)
					left=curr[col-1];
				curr[col] = up+left;
			}
		}
		prev=curr;
	}
	return prev[n-1];
}
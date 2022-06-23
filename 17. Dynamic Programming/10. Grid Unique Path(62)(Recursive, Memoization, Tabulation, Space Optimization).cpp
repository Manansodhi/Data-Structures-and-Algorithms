//GRID UNIQUE PATH leetcode 62
/*
You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination 
is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the 
total number of unique paths from point ‘A’ to point ‘B’.In other words, you will be given 
the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number 
of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example in a 
given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

Constraints:
1 ≤ T ≤ 100
1 ≤ M ≤ 15
1 ≤ N ≤ 15

Where ‘M’ is the number of rows and ‘N’ is the number of columns in the matrix. 

Time limit: 1 sec
Sample Input 1:
2
2 2
1 1
Sample Output 1:
2
1
Explanation Of Sample Output 1:
In test case 1, we are given a 2 x 2 matrix, to move from matrix[0][0] to matrix[1][1] we have the 
following possible paths.

Path 1 = (0, 0) -> (0, 1) -> (1, 1)
Path 2 = (0, 0) -> (1, 0) -> (1, 1)

Hence a total of 2 paths are available, so the output is 2.

In test case 2, we are given a 1 x 1 matrix, hence we just have a single cell which is both the 
starting and ending point. Hence the output is 1.
Sample Input 2:
2
3 2
1 6
Sample Output 2:
3
1
Explanation Of Sample Output 2:
In test case 1, we are given a 3 x 2 matrix, to move from matrix[0][0] to matrix[2][1] we have the 
following possible paths.

Path 1 = (0, 0) -> (0, 1) -> (1, 1) -> (2, 1)
Path 2 = (0, 0) -> (1, 0) -> (2, 0) -> (2, 1)
Path 3 =  (0, 0) -> (1, 0) -> (1, 1) -> (2, 1)

Hence a total of 3 paths are available, so the output is 3.

In test case 2, we are given a 1 x 6 matrix, hence we just have a single row to traverse and thus 
total path will be 1.
*/



//Recursive  TLE  TLE
//TIME: O(2^(m*n))
//SPACE: O(pathLength) pathLength = (m-1)+(n-1)

int f(int row, int col){
	if(row == 0 && col == 0)return 1;
	if(row < 0 || col < 0) return 0;
	int up = f(row-1, col);
	int left = f(row, col-1);

	return up+left;
}

int uniquePaths(int m, int n){
	return f(m-1, n-1);
}

//Memiozation
//TIME: O(n*m) maximum number of recursive calls are n*m
//SPACE: O(pathLength) + O(n*m) Recursive stack space --> pathLength = (m-1)+(n-1) 
//and n*m --> for dp[][]array
int f(int row, int col, vector<vector<int>> &dp){
	if(row == 0 && col == 0)return 1;
	if(row < 0 || col < 0) return 0;
	if(dp[row][col] != -1)
		return dp[row][col];
	int up = f(row-1, col, dp);
	int left = f(row, col-1, dp);

	return dp[row][col] = up+left;
}

int uniquePaths(int m, int n){
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return f(m-1, n-1, dp);
}


//TABULATION
//TIME: O(n*m) Nested for loop
//SPACE: O(n*m) only for dp[][] array and not any for Recursive stack space

int uniquePaths(int m, int n){
	int dp[m][n];
	for(int row = 0; row < m; row++){
		for(int col = 0; col < n; col++){
			if(row==0 && col==0)
				dp[row][col]=1;
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

int uniquePaths(int m, int n){
	vector<int> prev(n,0);
	for(int row = 0; row < m; row++){
		//current Row that is being computed
		vector<int>curr(n,0);
		for(int col = 0; col < n; col++){
			if(row==0 && col==0)//now current row is curr so replace dp[i] with curr
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
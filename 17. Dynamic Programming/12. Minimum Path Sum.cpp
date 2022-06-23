

//RECURSION

int f(int row, int col, vector<vector<int>> &grid){
	//bae case
	if(row==0 && col==0){
		return grid[0][0];
	}

	if(row<0 || col<0){
		return 1e9;
	}

	int up = grid[row][col] + f(row-1, col, grid);
	int left = grid[row][col] + f(row, col-1, grid);

	return min(up,left);
}

int minPathSum(vector<vector<int>>& grid){
	int n = grid.size();
	int m = grid[0].size();
	

	return f(n-1, m-1, grid);
}


//MEMOIZATION

int f(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
	//bae case
	if(row==0 && col==0){
		return grid[0][0];
	}

	if(row<0 || col<0){
		return 1e9;
	}
	
	if(dp[row][col] != -1){
		return dp[row][col];
	}

	int up = grid[row][col] + f(row-1, col, grid, dp);
	int left = grid[row][col] + f(row, col-1, grid, dp);

	return dp[row][col] = min(up,left);
}

int minPathSum(vector<vector<int>>& grid){
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> dp(n,vector<int>(m,-1));

	return f(n-1, m-1, grid, dp);
}

//TABULATION

int minPathSum(vector<vector<int>>& grid){
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> dp(n,vector<int>(m,0));

	for(int row=0;row<n;row++){
		for(int col=0;col<m;col++){
			if(row==0 && col==0){
				dp[row][col]=grid[row][col];
			}
			else{
				int up = grid[row][col];
				if(row>0)
					up += dp[row-1][col];
				else
					up = 1e9;
				int left = grid[row][col];
				if(col>0)
					left += dp[row][col-1];
				else
					left = 1e9;

				dp[row][col] = min(up, left);
			}
		}
	}

	return dp[n-1][m-1];
}


//SPACE OPTIMIZATION


int minPathSum(vector<vector<int>>& grid){
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> dp(n,vector<int>(m,0));

	vector<int>prev(m,0);
	for(int row=0;row<n;row++){
		vector<int>curr(m,0);
		for(int col=0;col<m;col++){
			if(row==0 && col==0){
				curr[col]=grid[row][col];
			}
			else{
				int up = grid[row][col];
				if(row>0)
					//Requiring previous row's j column
					up += prev[col];
				else
					up = 1e9;
				int left = grid[row][col];
				if(col>0)
					//requiring current row j-1 column
					left += curr[col-1];
				else
					left = 1e9;

				curr[col] = min(up, left);
			}
		}
		prev=curr;
	}

	return prev[m-1];
}
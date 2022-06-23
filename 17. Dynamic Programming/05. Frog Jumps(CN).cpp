 

 //Brute Force Recursion
//Will give TLE
 int f(int idx, vector<int> &heights){
 	if(idx==0)return 0;

 	int left = f(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
 	int right = INT_MAX;
 	if(idx>1)
 		right - f(idx-2, heights) + abs(heights[idx] - heights[idx-2]);

 	return min(left, right);
 }


 int frogJumps(int n, vector<int> &heights){
 	return f(n-1, heights);
 }




 //Dynamic Programming Approch

 int f(int idx, vector<int> &heights, vector<int>&dp){
 	if(idx==0)return 0;

 	if(dp[idx] != -1){
 		return dp[idx];
 	}
 	int left = f(idx-1, heights, dp) + abs(heights[idx] - heights[idx-1]);
 	int right = INT_MAX;
 	if(idx>1)
 		right - f(idx-2, heights, dp) + abs(heights[idx] - heights[idx-2]);

 	return dp[idx] = min(left, right);
 }


 int frogJumps(int n, vector<int> &heights){
 	vector<int>dp(n+1,-1);
 	return f(n-1, heights,dp);
 }

 //Tabulation

  int frogJumps(int n, vector<int> &heights){
 	vector<int>dp(n+1,0);
 	dp[0]=0;
 	for(int i=1;i<n;i++){
 		int left = dp[i-1] + abs(heights[i]-heights[i-1]);
 		int right = INT_MAX;
 		if(right>1){
 			right = dp[i-2] + abs(heights[i]-heights[i-2]);
 		}
 		dp[i]=min(left,right);
 	}

 	return dp[n-1];
 }


 //SPACE OPTIMIZATION
 //TIME: O(N)
 //SPACE: O(1)
   int frogJumps(int n, vector<int> &heights){
 	int prev=0,prev2=0;
 	for(int i=1;i<n;i++){
 		int left = prev + abs(heights[i]-heights[i-1]);
 		int right = INT_MAX;
 		if(right>1){
 			right = prev2 + abs(heights[i]-heights[i-2]);
 		}
 		int curri=min(left,right);
 		prev2 = prev;
 		prev = curri;
 	}

 	return prev;
 }

/*
Rod cutting problem
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has 
a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling 
its pieces.
Note:
1. The sizes will range from 1 to ‘N’ and will be integers.
2. The sum of the pieces cut should be equal to ‘N’.
3. Consider 1-based indexing.

Since 1-based indexing is considered, the 0th index of the vector will represent sub-length 
1 of the rod. Hence the (N - 1)th index would represent the cost for the length ‘N’. 

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= A[i] <= 100

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod, and A[i] is 
the cost of sub-length.

Time limit: 1 sec.
Sample Input 1:
2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20

Sample Output 1:
12
24

Explanation Of Sample Input 1:
Test case 1:
All possible partitions are:
1,1,1,1,1           max_cost=(2+2+2+2+2)=10
1,1,1,2             max_cost=(2+2+2+5)=11
1,1,3               max_cost=(2+2+7)=11
1,4                 max_cost=(2+8)=10
5                   max_cost=(10)=10
2,3                 max_cost=(5+7)=12
1,2,2               max _cost=(1+5+5)=12    

Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost which is 12.

Test case 2:
Possible partitions are:
1,1,1,1,1,1,1,1         max_cost=(3+3+3+3+3+3+3+3)=24
1,1,1,1,1,1,2           max_cost=(3+3+3+3+3+3+5)=23
1,1,1,1,2,2             max_cost=(3+3+3+3+5+5)=22
and so on….

If we cut the rod into 8 pieces of length 1, for each piece 3 adds up to the cost. Hence for 
8 pieces, we get 8*3 = 24.

Sample Input 2:
1
6
3 5 6 7 10 12

Sample Output 2:
18
*/


//RECURSION TLE TLE
int f(int idx, int N, vector<int>price){
    //base case
    if(idx==0)
        return N*price[0];
    
    int notTake = 0+f(idx-1,N,price);
    int take=-1e8;
    int rodLength = idx+1;
    if(rodLength<=N){
        take=price[idx]+f(idx,N-rodLength,price);
    }
    return max(notTake, take);
}

int cutRod(vector<int> &price, int n)
{
	return f(n-1,n,price);
}

//MEMOIZATION
int f(int idx, int N, vector<int>price, vector<vector<int>> &dp){
    //base case
    if(idx==0)
        return N*price[0];
    
    if(dp[idx][N] != -1){
        return dp[idx][N];
    }
    
    int notTake = 0+f(idx-1,N,price,dp);
    int take=-1e8;
    int rodLength = idx+1;
    if(rodLength<=N){
        take=price[idx]+f(idx,N-rodLength,price,dp);
    }
    return dp[idx][N] = max(notTake, take);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1, -1));
    return f(n-1,n,price,dp);
}

//TABULATION

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1, 0));
    //base case
    for(int N=0;N<=n;N++){
        dp[0][N] = N*price[0];
    }
    
    for(int idx=1;idx<=n-1;idx++){
        for(int N=0;N<=n;N++){
            int notTake = 0+dp[idx-1][N];
            int take=-1e8;
            int rodLength = idx+1;
            if(rodLength<=N){
                take=price[idx]+dp[idx][N-rodLength];
            }
             dp[idx][N] = max(notTake, take);
        }
    }
    return dp[n-1][n];
}

//SPACE OPTI<IZATION

int cutRod(vector<int> &price, int n)
{
    vector<int>prev(n+1, 0), curr(n+1,0);
    //base case
    for(int N=0;N<=n;N++){
        prev[N] = N*price[0];
    }
    
    for(int idx=1;idx<=n-1;idx++){
        for(int N=0;N<=n;N++){
            int notTake = 0+prev[N];
            int take=-1e8;
            int rodLength = idx+1;
            if(rodLength<=N){
                take=price[idx]+curr[N-rodLength];
            }
             curr[N] = max(notTake, take);
        }
        prev=curr;
    }
    return prev[n];
}


//1-D Array Space Optimization
int cutRod(vector<int> &price, int n)
{
    vector<int>prev(n+1, 0);
    //base case
    for(int N=0;N<=n;N++){
        prev[N] = N*price[0];
    }
    
    for(int idx=1;idx<=n-1;idx++){
        for(int N=0;N<=n;N++){
            int notTake = 0+prev[N];
            int take=-1e8;
            int rodLength = idx+1;
            if(rodLength<=N){
                take=price[idx]+prev[N-rodLength];
            }
             prev[N] = max(notTake, take);
        }
    }
    return prev[n];
}
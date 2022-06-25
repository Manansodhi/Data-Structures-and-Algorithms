/*
Counts Subsets with Sum K
You are given an array (0-based indexing) of positive integers and you have to tell how many different 
ways of selecting the elements from the array are there such that the sum of chosen elements is equal
to the target number “tar”.

For Example:
If N = 4 and tar = 3 and the array elements are [1, 2, 2, 3], then the number of possible ways are:
{1, 2}
{3}
{1, 2}
Hence the output will be 3.

Constraints:
1 <= T <= 10
1 <= N <= 100
1 <= nums[i] <= 1000
1 <= tar <= 1000

Time limit: 1 sec
Sample Input 1 :
2
4 3
1 2 2 3
2 3
1 2

Sample Output 1 :
3
1

Explanation For Sample Output 1:
For the first test case, N = 4 and tar = 3 and array elements are [1, 2, 2, 2,3] then the number of 
possible ways of making sum = 5 are:
{1,2}
{3}
{1,2}
Hence the output will be 3.

For the second test case, N = 2 and tar = 3 and array elements are [1, 2], there is only one way of 
making sum = 3 which is {1,2}.
Hence the output will be 1.

Sample Input 2 :
2
3 4
12 1 3
2 41
2 34

Sample Output 2 :
1
0
*/

//RECURSION   TLE TLE
int f(int idx, int target, vector<int> &arr){
    //base case
    if(target==0)
        return 1;
    if(idx==0)
        return (arr[0] == target);
    
    int notPick = f(idx-1, target, arr);
    int pick = 0;
    if(arr[idx]<=target){
        pick = f(idx-1, target-arr[idx], arr);
    }
    
    return pick + notPick;
}

int findWays(vector<int> &arr, int target)
{
    int n = arr.size();
    return f(n-1, target, arr);
}


//MEMOIZATION
int f(int idx, int target, vector<int> &arr, vector<vector<int>> &dp){
    //base case
    if(target==0)
        return 1;
    if(idx==0)
        return (arr[0] == target);
    if(dp[idx][target] != -1){
        return dp[idx][target];
    }
    
    int notPick = f(idx-1, target, arr, dp);
    int pick = 0;
    if(arr[idx]<=target){
        pick = f(idx-1, target-arr[idx], arr, dp);
    }
    
    return dp[idx][target] = pick + notPick;
}

int findWays(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return f(n-1, target, arr, dp);
}


//TABULATION

int findWays(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    
    //base cases
    for(int idx=0;idx<n;idx++){
        dp[idx][0] = 1;
    }
    if(arr[0]<=target)
        dp[0][arr[0]] = 1;
    
    //Exploring all paths
    for(int idx=1;idx<n;idx++){
        for(int sum=0;sum<=target;sum++){
            int notPick = dp[idx-1][sum];
            int pick = 0;
            if(arr[idx]<=sum){
                pick = dp[idx-1][sum-arr[idx]];
            }
    
             dp[idx][sum] = pick + notPick;            
        }
    }
    return dp[n-1][target];
}

//SPACE OPTIMIZATION
int findWays(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<int>prev(target+1, 0), curr(target+1, 0);
    
    //base cases
    prev[0] = curr[0] =1;
    if(arr[0]<=target)
        prev[arr[0]] = 1;
    
    //Exploring all paths
    for(int idx=1;idx<n;idx++){
        for(int sum=0;sum<=target;sum++){
            int notPick = prev[sum];
            int pick = 0;
            if(arr[idx]<=sum){
                pick = prev[sum-arr[idx]];
            }
    
             curr[sum] = pick + notPick;            
        }
        prev=curr;
    }
    return prev[target];
}
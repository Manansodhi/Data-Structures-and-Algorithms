/*
0 1 Knapsack

A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Time Limit: 1 second

Sample Input:
1 <- number of test case
4
1 2 4 5
5 4 8 6
5
Sample Output:
13
*/



//RECURSION TLE  TLE
int f(int idx, int bagWT, vector<int> &wt, vector<int> &val){
    if(idx==0){
        if(wt[idx] <= bagWT){
            return val[idx];
        }
        else{
            return 0;
        }
    }
        int notPick = 0 + f(idx-1, bagWT, wt, val);
        int pick = -1e8;
        if(wt[idx] <= bagWT){
            pick = val[idx] + f(idx-1, bagWT-wt[idx], wt, val);
        }
    return max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return f(n-1, maxWeight, weight, value);
}



//MEMOIZATION

int f(int idx, int bagWT, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
    if(idx==0){
        if(wt[idx] <= bagWT){
            return val[idx];
        }
        else{
            return 0;
        }
    }
    if(dp[idx][bagWT] != -1){
        return dp[idx][bagWT];
    }
        int notPick = 0 + f(idx-1, bagWT, wt, val, dp);
        int pick = -1e8;
        if(wt[idx] <= bagWT){
            pick = val[idx] + f(idx-1, bagWT-wt[idx], wt, val, dp);
        }
    return dp[idx][bagWT] = max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{    
    vector<vector<int>> dp(n,vector<int>(maxWeight+1, -1));
    return f(n-1, maxWeight, weight, value, dp);
}




//SPACE OPTIMIZATION
int knapsack(vector<int> weight, vector<int> value, int n, int bagWT) 
{    
    vector<int> prev(bagWT+1,0), curr(bagWT+1,0);
    
    //base case
    for(int W = weight[0]; W<=bagWT; W++)
        prev[W] = value[0];
        //dp[idx][bagWT] for every idx=0 and when wt[0]<=bagWT means last item bag m tabhi ayegi jab badWT ki capacity jada hoga weight item se agar bag ki capacity kam h toh usko bag m nahi dal sakte
    
    for(int idx=1; idx<n; idx++){
        for(int W=0; W<=bagWT;W++){
            int notPick = 0 + prev[W];
            int pick = -1e8;
            if(weight[idx] <= W){
                pick = value[idx] + prev[W-weight[idx]];
            }
         curr[W] = max(pick, notPick);
        }
        prev=curr;
    }
    return prev[bagWT];
}
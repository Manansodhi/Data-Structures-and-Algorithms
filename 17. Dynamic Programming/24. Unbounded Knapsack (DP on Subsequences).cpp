/*
Unbounded Knapsack
You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with weight capacity 
‘W’. You need to fill the knapsack with the items in such a way that you get the maximum profit. 
You are allowed to take one item multiple times.

For Example
Let us say we have 'N' = 3 items and a knapsack of capacity 'W' =  10
'PROFIT' = { 5, 11, 13 }
'WEIGHT' = { 2, 4, 6 }

We can fill the knapsack as:
1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 i.e ‘27’. Therefore maximum profit = 27.
Constraints
1 <= T <= 50
1 <= N <= 10^3
1 <= W <= 10^3
1 <= PROFIT[ i ] , WEIGHT[ i ] <= 10^8

Time Limit: 1sec
Sample Input 1
2
3 15
7 2 4
5 10 20
2 3
6 12
4 17

Sample Output 1
21
0

Explanation Of Sample Input 1
Test Case 1:  The given knapsack capacity is 15. We can fill the knapsack as [5, 5, 5] and 
[10, 5]. We will get a maximum profit of 21.

Test Case 2: We can clearly see that no item has wait less than knapsack capacity. Therefore 
we can not fill knapsack with any item.
Sample Input 2
2
4 7
3 4 5 1
4 1 2 3
3 9
1 2 3
1 3 5

Sample Output 2
28
9


*/


//RECURSION
int f(int idx, int bagWT, vector<int> &profit, vector<int> &weight){
    //base case
    if(idx==0){
        return (bagWT/weight[0])*profit[0];
    }
    
    int notTake = 0+f(idx-1, bagWT, profit, weight);
    int take = -1e9;
    if(weight[idx]<=bagWT){
        take = profit[idx]+f(idx,bagWT-weight[idx],profit,weight);
    }
    return max(notTake, take);
}


int unboundedKnapsack(int n, int bagWT, vector<int> &profit, vector<int> &weight) {
      return f(n-1, bagWT, profit, weight);
    }


  //Memoization
  int f(int idx, int bagWT, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
   // base case
    if(idx==0){
        return (bagWT/weight[0])*profit[0];
    }
    if(dp[idx][bagWT] != -1){
      return dp[idx][bagWT];
    }
    
    int notTake =0+ f(idx-1, bagWT, profit, weight, dp);
    int take=-1e9;
    if(weight[idx]<=bagWT){
      take =profit[idx]+ f(idx, bagWT-weight[idx], profit, weight, dp);
    }
    return dp[idx][bagWT] = max(take,notTake);
  }
    int unboundedKnapsack(int n, int bagWT, vector<int> &profit, vector<int> &weight) {
      vector<vector<int>> dp(n, vector<int>(bagWT+1, -1));
      return f(n-1, bagWT, profit, weight, dp);
    }

 //Tabulation

    int unboundedKnapsack(int n, int bagWT, vector<int> &profit, vector<int> &weight) {
      vector<vector<int>> dp(n, vector<int>(bagWT+1, 0));
        
        //base case
        for(int W=0;W<=bagWT;W++){
            dp[0][W]=(W/weight[0])*profit[0];
        }
        
        for(int idx=1;idx<=n-1;idx++){
            for(int W=0;W<=bagWT;W++){
                int notTake =0+ dp[idx-1][W];
                int take=-1e9;
                if(weight[idx]<=W){
                    take =profit[idx]+ dp[idx][W-weight[idx]];
                }
                 dp[idx][W] = max(take,notTake);
            }
        }
      return dp[n-1][bagWT];
    }

//Space Optimized

int unboundedKnapsack(int n, int bagWT, vector<int> &profit, vector<int> &weight) {
      vector<int>prev(bagWT+1, 0), curr(bagWT+1, 0);
        
        //base case
        for(int W=0;W<=bagWT;W++){
            prev[W]=(W/weight[0])*profit[0];
        }
        
        for(int idx=1;idx<=n-1;idx++){
            for(int W=0;W<=bagWT;W++){
                int notTake =0+ prev[W];
                int take=-1e9;
                if(weight[idx]<=W){
                    take =profit[idx]+ curr[W-weight[idx]];
                }
                 curr[W] = max(take,notTake);
            }
            prev = curr;
        }
      return prev[bagWT];
    }



//1-d Array Space Optimized

int unboundedKnapsack(int n, int bagWT, vector<int> &profit, vector<int> &weight) {
      vector<int>prev(bagWT+1, 0);
        
        //base case
        for(int W=0;W<=bagWT;W++){
            prev[W]=(W/weight[0])*profit[0];
        }
        
        for(int idx=1;idx<=n-1;idx++){
            for(int W=0;W<=bagWT;W++){
                int notTake =0+ prev[W];
                int take=-1e9;
                if(weight[idx]<=W){
                    take =profit[idx]+ prev[W-weight[idx]];
                }
                 prev[W] = max(take,notTake);
            }
        }
      return prev[bagWT];
    }
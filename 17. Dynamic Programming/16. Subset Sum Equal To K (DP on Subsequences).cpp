/*
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check
if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. 
Hence, return true.

Constraints:
1 <= T <= 5
1 <= N <= 10^3
0 <= ARR[i] <= 10^9
0 <= K <= 10^9

Time Limit: 1 sec
Sample Input 1:
2
4 5
4 3 2 1
5 4
2 5 1 6 7

Sample Output 1:
true
false

Explanation For Sample Input 1:
In example 1, ‘ARR’ is {4,3,2,1} and ‘K’ = 5. There exist 2 subsets with sum = 5. These are {4,1} 
and {3,2}. Hence, return true.
In example 2, ‘ARR’ is {2,5,1,6,7} and ‘K’ = 4. There are no subsets with sum = 4. Hence, return 
false.

Sample Input 2:
2
4 4
6 1 2 1
5 6
1 7 2 9 10

Sample Output 2:
true
false

Explanation For Sample Input 2:
In example 1, ‘ARR’ is {6,1,2,1} and ‘K’ = 4. There exist 1 subset with sum = 4. That is {1,2,1}. 
Hence, return true.
In example 2, ‘ARR’ is {1,7,2,9,10} and ‘K’ = 6. There are no subsets with sum = 6. Hence, 
return false.

*/


//RECURSIVE
bool f(int idx, int target, vector<int> &arr){
    if(target==0)return true;
    if(idx==0)return (arr[0]==target);
    
    bool notTake = f(idx-1,target,arr);
    bool take=false;
    if(target>=arr[idx]){
        take=f(idx-1,target-arr[idx],arr);
    }
    
    return notTake or take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(n-1,k,arr);
}


//Memoization

bool f(int idx, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target==0)return true;
    if(idx==0)return (arr[0]==target);
    if(dp[idx][target] != -1)
        return dp[idx][target];
    
    bool notTake = f(idx-1,target,arr,dp);
    bool take=false;
    if(target>=arr[idx]){
        take=f(idx-1,target-arr[idx],arr,dp);
    }
    
    return dp[idx][target] = notTake or take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}


//Tabulation
bool subsetSumToK(int n, int sum, vector<int> &arr) {
vector<vector<bool>> dp(n, vector<bool>(sum+1,0));
    
 //base case
    for(int i=0;i<n;i++){
      dp[i][0]=true;
    }
    dp[0][arr[0]] = true;
    
    for(int idx=1; idx<n; idx++){
      for(int target=1; target<=sum; target++){
        bool notTake = dp[idx-1][target];
        bool take=false;
        if(target>=arr[idx]){
          take=dp[idx-1][target-arr[idx]];
         }
    
         dp[idx][target] = notTake or take;
      }
    }
   return dp[n-1][sum];
}


//Space Otimization
bool subsetSumToK(int n, int sum, vector<int> &arr) {
vector<bool> prev(sum+1, 0), curr(sum+1,0); 
    
 //base case
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;
    
    for(int idx=1; idx<n; idx++){
      for(int target=1; target<=sum; target++){
        bool notTake = prev[target];
        bool take=false;
        if(target>=arr[idx]){
          take=prev[target-arr[idx]];
         }
         curr[target] = notTake or take;
      }
       prev = curr;
    }
   return prev[sum];
}
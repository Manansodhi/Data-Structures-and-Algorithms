/*
Count Partitions With Given Difference | Dp on Subsequences

Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the 
original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.
Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ 
and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return 
it modulo ‘10^9 + 7’.
Note that the sum of the elements of an empty subset is 0.

For Example :
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in 
the 2nd partition, S1 contains 5 from index 2.

Constraints :
1 ≤ T ≤ 10
1 ≤ N ≤ 50
0 ≤ D ≤ 2500
0 ≤ ARR[i] ≤ 50

Time limit: 1 sec
Sample Input 1 :
2
4 3
5 2 6 4
4 0
1 1 1 1

Sample Output 1 :
1
6

Explanation For Sample Input 1 :
For test case 1:
We will print 1 because :
There is only one possible partition of this array.
Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3

For test case 2:
We will print 6 because :
The partition {1, 1}, {1, 1} is repeated 6 times:
Partition 1 : {ARR[0], ARR[1]}, {ARR[2], ARR[3]}
Partition 2 : {ARR[0], ARR[2]}, {ARR[1], ARR[3]}
Partition 3 : {ARR[0], ARR[3]}, {ARR[1], ARR[2]}
Partition 4 : {ARR[1], ARR[2]}, {ARR[0], ARR[3]}
Partition 5 : {ARR[1], ARR[3]}, {ARR[0], ARR[2]}
Partition 6 : {ARR[2], ARR[3]}, {ARR[0], ARR[1]}
The difference is in the indices chosen for the subset S1(or S2).

Sample Input 2 :
3
3 1
4 6 3
5 0
3 1 1 2 1
5 1
3 2 2 5 1

Sample Output 2 :
1
6
3
*/


int mod = (int)(1e9+7); 
//MEMOIZATION
int f(int idx, int target, vector<int> &arr, vector<vector<int>> &dp){
    //base case
      if(idx==0){
          if(target==0 && arr[0]==0)return 2;
          if(target==0 || target==arr[0])return 1;
          return 0;
      }
    if(dp[idx][target] != -1){
        return dp[idx][target];
    }
    
    int notPick = f(idx-1, target, arr, dp);
    int pick = 0;
    if(arr[idx]<=target){
        pick = f(idx-1, target-arr[idx], arr, dp);
    }
    
    return dp[idx][target] = (pick + notPick)%mod;
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
    if(arr[0] == 0)
        dp[0][0]=2;
    else
        dp[0][0]=1;
    if(arr[0]!=0 && arr[0]<=target)
        dp[0][arr[0]] = 1;
    
    //Exploring all paths
    for(int idx=1;idx<n;idx++){
        for(int sum=0;sum<=target;sum++){
            int notPick = dp[idx-1][sum];
            int pick = 0;
            if(arr[idx]<=sum){
                pick = dp[idx-1][sum-arr[idx]];
            }
    
             dp[idx][sum] = (pick + notPick)%mod;            
        }
    }
    return dp[n-1][target];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum=0;
    for(int i=0;i<n;i++)totalSum += arr[i];
    if((totalSum-d < 0) || (totalSum-d)%2 ) return false;
    return findWays(arr, (totalSum-d)/2);
}


//Space optimization
int findWays(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<int>prev(target+1,0), curr(target+1,0);
    
    //base cases
    if(arr[0] == 0)
        prev[0]=2;
    else
        prev[0]=1;
    if(arr[0]!=0 && arr[0]<=target)
        prev[arr[0]] = 1;
    
    //Exploring all paths
    for(int idx=1;idx<n;idx++){
        for(int sum=0;sum<=target;sum++){
            int notPick = prev[sum];
            int pick = 0;
            if(arr[idx]<=sum){
                pick = prev[sum-arr[idx]];
            }
    
             curr[sum] = (pick + notPick)%mod;            
        }
        prev=curr;
    }
    return prev[target];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum=0;
    for(int i=0;i<n;i++)totalSum += arr[i];
    if((totalSum-d < 0) || (totalSum-d)%2 ) return false;
    return findWays(arr, (totalSum-d)/2);
}



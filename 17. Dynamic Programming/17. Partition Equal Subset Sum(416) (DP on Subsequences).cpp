/*
416. Partition Equal Subset Sum

Given a non-empty array nums containing only positive integers, find if the array can be partitioned
into two subsets such that the sum of elements in both subsets is equal.

 
Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 
Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

class Solution {
public:
  
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

bool canPartition( vector<int> &arr) {
  int sum = 0;
  int n = arr.size();
  for(int i = 0; i<n ; i++){
    sum += arr[i];
  }
 if(sum & 1) //if sum is odd
    return false;
 sum = sum/2;
    return f(n-1,sum,arr);
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

bool canPartition( vector<int> &arr) {
  int sum = 0;
  int n = arr.size();
  for(int i = 0; i<n ; i++){
    sum += arr[i];
  }
 if(sum & 1) //if sum is odd
    return false;
 sum = sum/2;
 vector<vector<int>> dp(n, vector<int>(sum+1,-1));
 return f(n-1,sum,arr,dp);
}
 
  
  //Tabulation
  bool canPartition( vector<int> &arr) {
  int sum = 0;
  int n = arr.size();
    //cout<<n<<endl;
  for(int i = 0; i<n ; i++){
    sum += arr[i];
  }
 if(sum & 1) //if sum is odd
    return false;
  if(n==1)
    return false;
 sum = sum/2;
 vector<vector<bool>> dp(n, vector<bool>(sum+1,0));
    
 //base case
    for(int i=0;i<n;i++){
      dp[i][0]=true;
    }
    if(arr[0]<=sum)
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
  
  
  //Space Optimization
  bool canPartition( vector<int> &arr) {
  int sum = 0;
  int n = arr.size();
    //cout<<n<<endl;
  for(int i = 0; i<n ; i++){
    sum += arr[i];
  }
 if(sum & 1) //if sum is odd
    return false;
  if(n==1)
    return false;
 sum = sum/2;
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
  
  
};
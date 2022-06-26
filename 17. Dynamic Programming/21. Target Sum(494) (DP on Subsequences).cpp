/*
494. Target Sum
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each 
integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to 
build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 
Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1
 
Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/
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
    
             dp[idx][sum] = (pick + notPick);            
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

int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n,target,arr);
}
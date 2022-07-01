/*
368. Largest Divisible Subset

Given a set of distinct positive integers nums, return the largest subset answer such that every pair 
(answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 
Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 
Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/

class Solution {
public:
    
 vector<int> largestDivisibleSubset(vector<int> &arr){
     sort(arr.begin(),arr.end());
    int n = arr.size();
      vector<int> dp(n,1), hash(n);
     int maxi=1;
     int lastIdx=0;
     for(int idx=0;idx<=n-1;idx++){ 
         hash[idx] = idx;
       for(int prev=0;prev<=idx-1;prev++){
         if((arr[idx]%arr[prev]==0) && 1+dp[prev]>dp[idx]){
             
           dp[idx] = 1+dp[prev];
             hash[idx] = prev;
         }
       }
       if(dp[idx] > maxi){
           maxi = dp[idx];
           lastIdx = idx;
       }
     }
    vector<int>temp;
     temp.push_back(arr[lastIdx]);
     while(hash[lastIdx] != lastIdx){
         lastIdx = hash[lastIdx];
         temp.push_back(arr[lastIdx]);
     }
     reverse(temp.begin(), temp.end());
    return temp;
    }
};
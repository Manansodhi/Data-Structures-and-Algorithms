/*
376. Wiggle Subsequence

A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between 
positive and negative. The first difference (if one exists) may be either positive or negative. A sequence 
with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate 
between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its 
first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving 
the remaining elements in their original order.
Given an integer array nums, return the length of the longest wiggle subsequence of nums.

 
Example 1:
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).

Example 2:
Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).

Example 3:
Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2
 
Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
 */

//GREEDY
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
      if(n==1)
        return 1;
      int prevDiff = nums[1]-nums[0];
      int count = (prevDiff != 0)?2:1;
      for(int i=2;i<n;i++){
        int currDiff = nums[i]-nums[i-1];
        if((currDiff>0 && prevDiff<=0) || (currDiff<0 && prevDiff>=0)){
          count++;
          prevDiff=currDiff;
        }
      }
      return count;
    }
};

//GREEDY
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int inc=1;
        int dec=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>0){
                inc=dec+1;
            }
            else if(nums[i]-nums[i-1]<0){
                dec=inc+1;
            }
        }
        return max(inc,dec);
        
    }
};


//DP
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        dp[0][0] = dp[0][1] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int diff = nums[i] - nums[j];
                if (diff == 0) continue;
                //positve
                if (diff > 0) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                //negative
                else dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
 
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
}
/*
189. Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 
Constraints:
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:
Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?*/

class Solution {
public:
    
// method 1 - k times apply single rotation
// method 2 - store first k elements in array then make the rest shift, then copy that k elements in the last
// method 3 - reverse k elements , reverse n-k elements(if req), then reverse the whole arraya
    void rotate(vector<int>& n, int k) 
    {
    
        k=k%n.size();
        reverse(n.begin(),n.end());
        reverse(n.begin(),n.begin()+k);
        reverse(n.begin()+k,n.end());
    }
};
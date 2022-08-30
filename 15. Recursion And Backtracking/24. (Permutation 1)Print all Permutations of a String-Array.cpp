/*
46. Permutations

Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.

 
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
 
Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/


class Solution {
public:
    
    void recursionPermutation(vector<int> &ds, vector<int> &nums, vector<vector<int>>  &ans, int freq[]){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                recursionPermutation(ds,nums,ans,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()];
        fill(freq,freq+nums.size(),0);
        // for(int i=0;i<nums.size();i++)
        //     freq[i]=0;
        recursionPermutation(ds,nums,ans,freq);
        return ans;
    }
    
  void recursionPermut(int idx, vector<int> &nums, vector<vector<int>> &ans){
      if(idx==nums.size()){
          ans.push_back(nums);
          return;
      }
      
      for(int i=idx;i<nums.size();i++){
          swap(nums[idx],nums[i]);
          recursionPermut(idx+1,nums,ans);
          swap(nums[idx],nums[i]);
      }
  }
    
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>>ans;
        recursionPermut(0,nums,ans);
        return ans;
    }
    
};
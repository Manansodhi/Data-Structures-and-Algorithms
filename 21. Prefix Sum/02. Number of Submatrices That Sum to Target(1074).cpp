/*
1074. Number of Submatrices That Sum to Target

Given a matrix and a target, return the number of non-empty submatrices that sum to target.


Example 1:
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.

Example 2:
Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

Example 3:
Input: matrix = [[904]], target = 0
Output: 0
 
Constraints:
1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
*/


class Solution {
public:
  
  int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
      int ans=0,prefixSum=0;
      int n=nums.size();
      
      for(int i=0;i<n;i++){
        prefixSum += nums[i];
        if(prefixSum == k)
          ans++;
        if(mp.find(prefixSum-k) != mp.end()){
          ans += mp[prefixSum-k];
        }
        if(mp.find(prefixSum) != mp.end()){
          mp[prefixSum]++;
        }
        else{
          mp[prefixSum]=1;
        }
      }
      return ans;
    }
  
  
  
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
       int count=0;
        for(int i=0; i<matrix.size(); i++){
            vector<int> sum(matrix[0].size(), 0);
            for(int j=i; j<matrix.size(); j++){
                for(int k=0; k<matrix[0].size(); k++){
                    sum[k] += matrix[j][k];
                }
                count += subarraySum(sum, target);
            }
        }
       
    return count;
    }
};


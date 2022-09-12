/*
363. Max Sum of Rectangle No Larger Than K

Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
It is guaranteed that there will be a rectangle with a sum no larger than k.

 
Example 1:
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).

Example 2:
Input: matrix = [[2,2,-1]], k = 3
Output: 3
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-105 <= k <= 105
*/



class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
      int res=INT_MIN,rows=matrix.size(),cols=matrix[0].size();
      for(int L=0;L<cols;++L){
        vector<int>sums(rows);
        for(int R=L;R<cols;++R){
          for(int i=0;i<rows;++i)
            sums[i]+=matrix[i][R];
          
          set<int>s = {0};
          int run_sum = 0;
          for(int sum:sums){
            run_sum += sum;
            auto it = s.lower_bound(run_sum - k);
            if(it!=end(s))
              res = max(res,run_sum - *it);
            s.insert(run_sum);
          }
        }
      }
      return res;
    }
};
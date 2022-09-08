/*
473. Matchsticks to Square
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
Return true if you can make this square and false otherwise.

Example 1:
Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

Example 2:
Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
 
Constraints:
1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108
*/

    int solve(vector<int>& matchsticks,vector<int> sideLengths, int i,int &side){
      if(i==matchsticks.size()){
          for(auto it:sideLengths)
              if(it!=side) 
                  return false;
          
          return true;
      }
        
        for(int j=0;j<4;j++){
            
            if(sideLengths[j]+matchsticks[i]<=side){
                sideLengths[j]+=matchsticks[i];
            if(solve(matchsticks,sideLengths,i+1,side))
                return true;
            
            // else backtrack
            sideLengths[j]-=matchsticks[i];
                
                if(sideLengths[j] == 0)
                break;
            }
            
        }
        
        return false;
    }

      bool makesquare(vector<int>& matchsticks) {
          int n=matchsticks.size();
          if(n<4)
              return false;

          int sum=0;
          for(auto i:matchsticks){
              sum+=i;
          }
        
          if(sum%4!=0)
              return false;
          
          vector<int> sideLengths={0,0,0,0};
          
          // sorting in descending order
          sort(matchsticks.begin(),matchsticks.end(),greater<int>());
          
          int side=sum/4;
          return solve(matchsticks,sideLengths,0,side);
    
    }


class Solution {
public:
    int n;
    int visited[16];
    
    bool possible(vector<int>& matchsticks, int numsIndex, int currSum, int& subsetSum, int k) {
        if(k == 1) return true;
        if(currSum == subsetSum) return possible(matchsticks, n-1, 0, subsetSum, k-1);
        
        for(int i = numsIndex; i>=0; i--) {
            if(visited[i] || currSum + matchsticks[i] > subsetSum) continue;
            visited[i] = 1;
            if(possible(matchsticks, i+1, currSum + matchsticks[i], subsetSum, k)) return true;
            visited[i] = 0;
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(begin(matchsticks), end(matchsticks), 0);
        int k = 4;
        if(sum%4 != 0) return false;
        memset(visited, 0, sizeof(visited));
        n = matchsticks.size();
        int subsetSum = sum/4;
        int numsIndex = n-1;
        int currSum = matchsticks[numsIndex];
        visited[numsIndex] = 1;
        
        return possible(matchsticks, numsIndex, currSum, subsetSum, k);
    }
};
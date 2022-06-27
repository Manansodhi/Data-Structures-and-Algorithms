/*
Longest Common Subsequence
Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the 'Longest Common 
Subsequence'. For a string 'str'(per se) of length K, the subsequences are the strings containing 
characters in the same relative order as they are present in 'str,' but not necessarily contiguous.
Subsequences contain all the strings of length varying from 0 to K.
Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec

Sample Input 1 :
adebc
dcadb
Sample Output 1 :
3

Explanation Of The Sample Output 1 :
Both the strings contain a common subsequence 'adb', which is the longest common subsequence 
with length 3. 

Sample Input 2 :
ab
defg

Sample Output 2 :
0

Explanation Of The Sample Output 2 :
The only subsequence that is common to both the given strings is an empty string("") of length 0.

*/

class Solution {
public:
  
//RECURSION
  int f(int idx1, int idx2, string s1, string s2){
    //base case
    if(idx1<0 || idx2<0)
      return 0;
    
    if(s1[idx1] == s2[idx2])
      return (1+f(idx1-1, idx2-1, s1, s2));
    return max(f(idx1-1,idx2,s1,s2), f(idx1,idx2-1,s1,s2));
  }
  
    int longestCommonSubsequence(string s1, string s2) {
      int n = s1.length();
      int m = s2.length();
      return f(n-1, m-1, s1, s2);
    }
  
  
//MEMOIZATION
  
int f(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp){
    //base case
    if(idx1<0 || idx2<0)
      return 0;
    
    if(dp[idx1][idx2] != -1)
      return dp[idx1][idx2];
    
    if(s1[idx1] == s2[idx2])
      return dp[idx1][idx2] = (1+f(idx1-1, idx2-1, s1, s2, dp));
    return dp[idx1][idx2] = max(f(idx1-1,idx2,s1,s2,dp), f(idx1,idx2-1,s1,s2,dp));
  }
  
    int longestCommonSubsequence(string s1, string s2) {
      int n = s1.length();
      int m = s2.length();
      vector<vector<int>> dp(n,vector<int>(m,-1));
      return f(n-1, m-1, s1, s2, dp);
    }
  
  //V.V.VIMP
  //Change base case by right shifting to write tabulation base easily
  int f(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp){
    //base case
    if(idx1==0 || idx2==0)//Changes made her when done right shifting
      return 0;
    
    if(dp[idx1][idx2] != -1)
      return dp[idx1][idx2];
    
    if(s1[idx1-1] == s2[idx2-1]) //Changes made her when done right shifting
      return dp[idx1][idx2] = (1+f(idx1-1, idx2-1, s1, s2, dp));
    return dp[idx1][idx2] = max(f(idx1-1,idx2,s1,s2,dp), f(idx1,idx2-1,s1,s2,dp));
  }
  
    int longestCommonSubsequence(string s1, string s2) {
      int n = s1.length();
      int m = s2.length();
      vector<vector<int>> dp(n+1,vector<int>(m+1,-1)); //also declare dp[n+1][m+1] now
      return f(n, m, s1, s2, dp);//Changes made her when done right shifting
    }
  
  
  //TABULATION
  
      int longestCommonSubsequence(string s1, string s2) {
      int n = s1.size();
      int m = s2.size();
      vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 
        
        //base case
        for(int idx1=0;idx1<=n;idx1++)
            dp[idx1][0]=0;
        for(int idx2=0;idx2<=m;idx2++)
            dp[0][idx2]=0;
             
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(s1[idx1-1] == s2[idx2-1]) 
                     dp[idx1][idx2] = (1+dp[idx1-1][idx2-1]);
                else 
                    dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
            }
        }
        
      return dp[n][m];
    }
  
  //SPACE OPTIMIZATION
    
    int longestCommonSubsequence(string s1, string s2) {
      int n = s1.size();
      int m = s2.size();
      vector<int>prev(m+1,0), curr(m+1,0); 
        
      //base case
        for(int idx1=0;idx1<=n;idx1++)
            prev[0]=0;
       
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(s1[idx1-1] == s2[idx2-1]) 
                     curr[idx2] = (1+prev[idx2-1]);
                else 
                    curr[idx2] = max(prev[idx2], curr[idx2-1]);
            }
            prev=curr;
        }
        
      return prev[m];
    }

};
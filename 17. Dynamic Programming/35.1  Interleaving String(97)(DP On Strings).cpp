/*
97. Interleaving String

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where they are divided into non-empty 
substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

Example 3:
Input: s1 = "", s2 = "", s3 = ""
Output: true
 
Constraints:
0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 */

 class Solution {
public:
  
  bool f(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp){
    //base case
    if(i==s1.length() && j==s2.length() && k==s3.length())
      return true;
    
    if(dp[i][j] != -1){
      return dp[i][j];
    }
 
    bool fromS1=false, fromS2=false;
    if(i != s1.length()){
      if(s1[i] == s3[k]){
        fromS1 = f(s1,s2,s3,i+1,j,k+1,dp);
      }
    }
    
    if(j != s2.length()){
      if(s2[j] == s3[k]){
        fromS2 = f(s1,s2,s3,i,j+1,k+1,dp);
      }
    }
    
    return dp[i][j] = fromS1 || fromS2;
  }
  
  
    bool isInterleave(string s1, string s2, string s3) {
      int n = s1.size(),m=s2.size();
      vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
      int i=0,j=0,k=0;
      return f(s1,s2,s3,0,0,0,dp);
    }
};
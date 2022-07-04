/*
132. Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0

Example 3:
Input: s = "ab"
Output: 1
 
Constraints:
1 <= s.length <= 2000
s consists of lowercase English letters only.
*/


class Solution {
public:
	
  //RECURSIVE
  bool isPalindrome(int i, int j, string &s){
    while(i<j){
      if(s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
  
  int f(int i, int n, string &s){
    if(i==n){
      return 0;
    }
    
    //string temp="";
    int minCost=1e9;
    for(int j=i;j<n;j++){
      //temp += s[j];
      if(isPalindrome(i,j,s)){
        int cost =1+f(j+1,n,s);
        minCost = min(minCost,cost);
      }
      
    }
    return minCost;
    
  }
  
    int minCut(string s) {
        int n = s.size();
      return f(0,n,s)-1;
    }
  
  
  //MEMOIZATION
   bool isPalindrome(int i, int j, string &s){
    while(i<j){
      if(s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
  
  int f(int i, int n, string &s, vector<int> &dp){
    if(i==n){
      return 0;
    }
    
    if(dp[i] != -1)
      return dp[i];
    
    //string temp="";
    int minCost=1e9;
    for(int j=i;j<n;j++){
      //temp += s[j];
      if(isPalindrome(i,j,s)){
        int cost =1+f(j+1,n,s,dp);
        minCost = min(minCost,cost);
      }
      
    }
    return dp[i] = minCost;
    
  }
  
    int minCut(string s) {
        int n = s.size();
      vector<int>dp(n,-1);
      return f(0,n,s,dp)-1;
    }
  
  //TABULATION
  
   bool isPalindrome(int i, int j, string &s){
    while(i<j){
      if(s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
  

  
    int minCut(string s) {
        int n = s.size();
      vector<int>dp(n+1,0);
      dp[n]=0;
      for(int i=n-1;i>=0;i--){
        int minCost=1e9;
        for(int j=i;j<n;j++){
          if(isPalindrome(i,j,s)){
            int cost =1+dp[j+1];
            minCost = min(minCost,cost);
          }
        }
         dp[i] = minCost;
      }
      return dp[0]-1;
    }
};
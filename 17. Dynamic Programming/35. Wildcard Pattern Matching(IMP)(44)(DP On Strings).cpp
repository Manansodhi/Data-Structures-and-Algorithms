/*
Wildcard Pattern Matching
Given a text and a wildcard pattern of size N and M respectively, implement a wildcard pattern matching 
algorithm that finds if the wildcard pattern is matched with the text. The matching should cover the 
entire text not partial text.
The wildcard pattern can include the characters ‘?’ and ‘*’
 ‘?’ – matches any single character 
 ‘*’ – Matches any sequence of characters(sequence can be of length 0 or more)
 Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= 200

Where 'N' denotes the length of 'TEXT' and 'M' denotes the length of 'PATTERN'.

'TEXT' and 'PATTERN' contain only lowercase letters and patterns may contain special characters ‘*’ 
and ‘?’
Time Limit: 1sec

Sample Input 1:
?ay
ray
ab*cd
abdefcd
ab?d
abcc

Sample Output 1:
True
True
False

Explanation Of The Sample Input1:
Test Case 1:
The pattern is “?ay” and the text is ray.
‘?’ can match a character so it matches with a character ‘r’ of the text and rest of the text matches 
with the pattern so we print True.

Test Case 2:
“ab” of text matches with “ab” of pattern and then ‘*’ of pattern matches with “def” of the text and 
“cd” of text matches with “cd” of the pattern. Whole text matches with the pattern so we print True.

Test Case 3:
“ab” of pattern matches with “ab” of text. ‘?’ of pattern matches with ‘c’ of the text but ‘d’ of the 
pattern do not match with ‘c’ of the text so we print False.

Sample Input 1:
ba*a?
baaabab
Sample Output 1:
True

*/

#include<bits/stdc++.h>

  //RECURSIVE TLE TLE
  
  int f(int i, int j, string &s1, string &s2){
    //base case
    
    if(i<0 && j<0)
      return true;
    if(i<0 && j>=0)
      return true;
    if(i>=0 && j<0){
      for (int idx=0; idx<=i; idx++){
        if(s1[idx] != '*')
          return false;
        return true;
      }
    }
    
      //Explore all paths
    if(s1[i] == s2[j] || s1[i] == '?')
      return f(i-1,j-1,s1,s2);
    if(s1[i] == '*'){
      return f(i-1,j,s1,s2) or f(i,j-1,s1,s2);
    }
    else{
      return false;
    }
    
  }
  
    bool isMatch(string s1, string s2) {
        int n = s1.size(), m = s2.size();
      return f(n-1,m-1,s1,s2);
    }

//MEMOIZATION
 int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    //base case
    
    if(i<0 && j<0)
      return true;
    if(i<0 && j>=0)
      return false;
    if(i>=0 && j<0){
      for (int idx=0; idx<=i; idx++){
        if(s1[idx] != '*')
          return false;
      }
      return true;
    }
    
    if(dp[i][j] != -1){
      return dp[i][j];
    }
    
      //Explore all paths
    if(s1[i] == s2[j] || s1[i] == '?')
      return dp[i][j] = f(i-1,j-1,s1,s2,dp);
    
    else{
      if(s1[i] == '*'){
        return dp[i][j] = f(i-1,j,s1,s2,dp) || f(i,j-1,s1,s2,dp);
      }
      else
        return dp[i][j] = false;
    }
  }
  
    bool wildcardMatching(string s1, string s2) {
        int n = s1.size(), m = s2.size();
      vector<vector<int>> dp(n,vector<int>(m,-1));
      return f(n-1,m-1,s1,s2,dp);
    }
  
//1-BasedIndexing
 int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    //base case    
    if(i==0 && j==0)
      return true;
    if(i==0 && j>0)
      return false;
    if(i>0 && j==0){
      for (int idx=1; idx<=i; idx++){
        if(s1[idx-1] != '*')
          return false;
      }
      return true;
    }
    
    if(dp[i][j] != -1){
      return dp[i][j];
    }
    
      //Explore all paths
    if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
      return dp[i][j] = f(i-1,j-1,s1,s2,dp);
    
    else{
      if(s1[i-1] == '*'){
        return dp[i][j] = f(i-1,j,s1,s2,dp) || f(i,j-1,s1,s2,dp);
      }
      else
        return dp[i][j] = false;
    }
  }
  
    bool wildcardMatching(string s1, string s2) {
        int n = s1.size(), m = s2.size();
      vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
      return f(n,m,s1,s2,dp);
    }

//TABULATION
  
    bool wildcardMatching(string s1, string s2) {
        int n = s1.size(), m = s2.size();
      vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int j=1; j<=m;j++)
            dp[0][j] = false;
        for(int i=1;i<=n;i++){
            bool flag = true;
            for(int idx=1; idx<=i;idx++){
                if(s1[idx-1] != '*'){
                    flag=false;
                    break;
                }
            }
            dp[i][0] = flag;
        } 
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
                     dp[i][j] = dp[i-1][j-1];
                else if(s1[i-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = false;  
            }
        }
      return dp[n][m];
    }


    //SPACE OPTIMIZATION V.V.V.IMP

    bool wildcardMatching(string s1, string s2) {
        int n = s1.size(), m = s2.size();
      vector<bool>prev(m+1,false), curr(m+1,false);

        //BASE CASES
        //prev means 0rth ROW and curr will be 1rst ROW
     //so dp[0]-->prev
        prev[0] = true;
        for(int j=1; j<=m;j++)
            prev[j] = false;
        
        
        
        //EXPLORE ALL POSSIBILTIES
        for(int i=1;i<=n;i++){
            //curr is the currrent row's column
            //and that curr's 0th row has to be assigned every time
            
            bool flag = true;
            for(int idx=1; idx<=i;idx++){
                if(s1[idx-1] != '*'){
                    flag=false;
                    break;
                }
            }
            //for every row  "dp[i]"
            //we are assigning 0rth column's value "[][0]"

            curr[0] = flag;
            //all above is copied from base becoz now we only have maintain 0rth column of 2 rows only 
            //prev and curr and that can be done by this for loop also
            
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
                     curr[j] = prev[j-1];
                else if(s1[i-1] == '*')
                    curr[j] = prev[j] || curr[j-1];
                else
                    curr[j] = false;  
            }
            prev = curr;
        }
      return prev[m];
    }
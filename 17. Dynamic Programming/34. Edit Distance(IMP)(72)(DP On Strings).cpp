/*
72. Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 
to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character
 
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 
Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters
*/

//RECURSION TLE TLE TLE
int f(int i, int j, string &s1, string &s2){
    //base case
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    
    //explore all possible paths
    //matches
    if(s1[i] == s2[j]){
        return 0+f(i-1, j-1, s1, s2);
    }
    else{
        return 1+min(f(i-1,j,s1,s2),min(f(i-1,j-1,s1,s2),f(i,j-1,s1,s2)));
    }
}


int editDistance(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    return f(n-1, m-1, s1, s2);
}


//MEMOIZATION

int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    //base case
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    //explore all possible paths
    //matches
    if(s1[i] == s2[j]){
        return dp[i][j] = 0+f(i-1, j-1, s1, s2, dp);
    }
    else{
        return dp[i][j] = 1+min(f(i-1,j,s1,s2,dp),min(f(i-1,j-1,s1,s2,dp),f(i,j-1,s1,s2,dp)));
    }
}


int editDistance(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1, m-1, s1, s2,dp);
}


//1-Based Indexing wala MEMOIZATION 

int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    //base case
    if(i==0)//changes made here due to 1-Based indexing
        return j;//changes made here due to 1-Based indexing
    if(j==0)//changes made here due to 1-Based indexing
        return i;//changes made here due to 1-Based indexing
    
    if(dp[i][j] != -1)
        return dp[i][j];
    //explore all possible paths
    //matches
    if(s1[i-1] == s2[j-1]){//changes made here due to 1-Based indexing
        return dp[i][j] = 0+f(i-1, j-1, s1, s2, dp);
    }
    else{
        return dp[i][j] = 1+min(f(i-1,j,s1,s2,dp),min(f(i-1,j-1,s1,s2,dp),f(i,j-1,s1,s2,dp)));
    }
}


int editDistance(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));//changes made here due to 1-Based indexing
    return f(n, m, s1, s2,dp);//changes made here due to 1-Based indexing
}


//TABULATION

int editDistance(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    //base case
    for(int j=0;j<=m;j++)
        dp[0][j]=j;
    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //explore all possible paths
            //matches
            if(s1[i-1] == s2[j-1]){
                 dp[i][j] = 0+dp[i-1][j-1];
            }
            //Does NOT matches
            else{
                 dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
    }
    
    return dp[n][m];
}


//SPACE OPTIMIZATION

int editDistance(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<int>prev(m+1,0), curr(m+1,0);
    
    //base case
    for(int j=0;j<=m;j++)
        prev[j]=j;
    for(int i=0;i<=n;i++)//NOT REQUIRED
        curr[0]=i;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //explore all possible paths
            //matches
            if(s1[i-1] == s2[j-1]){
                 curr[j] = 0+prev[j-1];
            }
            //Does NOT matches
            else{
                 curr[j] = 1+min(prev[j],min(prev[j-1],curr[j-1]));
            }
        }
        prev=curr;
    }
    
    return prev[m];
}
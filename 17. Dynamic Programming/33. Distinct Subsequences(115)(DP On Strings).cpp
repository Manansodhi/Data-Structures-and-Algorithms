/*
115. Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which equals t.
A string's subsequence is a new string formed from the original string by deleting some (can be none) 
of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a 
subsequence of "ABCDE" while "AEC" is not).
The test cases are generated so that the answer fits on a 32-bit signed integer.

 
Example 1:
Input: s = "rabbbit", t = "rabbit"

Output: 3

Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit

Example 2:
Input: s = "babgbag", t = "bag"

Output: 5

Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
 
Sample Input 1 :
13 2
codingniinjas
in
10 3
brootgroot
brt

Sample Output 1 :
5
3

Explanation For Sample Input 1 :
For the first test case, the following subsequences formed by characters at given indices (1-based) of 
TEXT are counted 
4 5
4 7
4 10
8 10
9 10 
The second test case will be similar as described above in the example.

Sample Input 2 :
2
16 3
dingdingdingding
ing
4 2
abac
cb

Sample Output 2 :
20
0

Constraints:
1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/


int mod = 1e9+7;
//RECURSION   TLE  TLE
int f(int i, int j, string &s1, string &s2){
    //BASE CASE
    if(j<0)
        return 1;
    if(i<0)
        return 0;
    
    //Explore All Possibilities
    if(s1[i] == s2[j]){
        return f(i-1,j-1,s1,s2) + f(i-1,j,s1,s2);
    }
    else{
        return f(i-1,j,s1,s2);
    }
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    return f(lt-1,ls-1,t,s);
} 

//MEMOIZATION
int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    //BASE CASE
    if(j<0)
        return 1;
    if(i<0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    //Explore All Possibilities
    if(s1[i] == s2[j]){
        return dp[i][j] = f(i-1,j-1,s1,s2,dp) + f(i-1,j,s1,s2,dp);
    }
    else{
        return dp[i][j] = f(i-1,j,s1,s2,dp);
    }
}


int subsequenceCounting(string &t, string &s, int n, int m) {
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,t,s,dp);
}

// 1-Based indexing
int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    //BASE CASE
    if(j==0)
        return 1;
    if(i==0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    //Explore All Possibilities
    if(s1[i-1] == s2[j-1]){
        return dp[i][j] = f(i-1,j-1,s1,s2,dp) + f(i-1,j,s1,s2,dp);
    }
    else{
        return dp[i][j] = f(i-1,j,s1,s2,dp);
    }
}


int subsequenceCounting(string &t, string &s, int n, int m) {
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return f(n,m,t,s,dp);
} 

//TABULATION

int subsequenceCounting(string &s1, string &s2, int n, int m) {
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    //base case
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    //can also remove this becoz we have already intialized the dp[][] full with 0 
    for(int j=1;j<=m;j++)
        dp[0][j]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                 dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
            else{
                 dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][m];
} 

//SPACE OPTIMIZIE
int subsequenceCounting(string &s1, string &s2, int n, int m) {
    vector<int>prev(m+1,0), curr(m+1,0);
    
    //base case
    prev[0] = curr[0] = 1;
    
    //what it is doing is that it is going to every row and at every column=0 it puts 1
//     for(int i=0;i<=n;i++)
//         dp[i][0]=1;
//     //can also remove this becoz we have already intialized the dp[][] full with 0 
//     for(int j=1;j<=m;j++)
//         dp[0][j]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                 curr[j] = (prev[j-1] + prev[j])%mod;
            }
            else{
                 curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    
    return prev[m];
} 



//1-D Array Space Optimization

int subsequenceCounting(string &s1, string &s2, int n, int m) {
    vector<int>prev(m+1,0), curr(m+1,0);
    
    //base case
    prev[0] = 1;
    
    //what it is doing is that it is going to every row and at every column=0 it puts 1
//     for(int i=0;i<=n;i++)
//         dp[i][0]=1;
//     //can also remove this becoz we have already intialized the dp[][] full with 0 
//     for(int j=1;j<=m;j++)
//         dp[0][j]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){ //Changes
            if(s1[i-1] == s2[j-1]){
                 prev[j] = (prev[j-1] + prev[j])%mod;//Changes
            }
            else{//ye else bhi remove kar sakte h kisi kam ka nahi h yw
                 prev[j] = prev[j];//Changes
            }
        }
    }
    
    return prev[m];
} 



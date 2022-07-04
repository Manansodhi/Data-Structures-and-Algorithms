/*
Boolean Evaluation

You are given an expression ‘EXP’ in the form of a string where operands will be : (TRUE and FALSE) and 
operators will be : (AND, OR, XOR). Now you have to find the number of ways we can parenthesize the 
expression such that it will evaluate to TRUE.

Note :
‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.

For example :

 Input: 
 'EXP’ = T|T & F
 There are total 2  ways to parenthesize this expression:
 (i) (T | T) & (F) = F
 (ii) (T) | (T & F) = T
 Out of 2 ways, one will result in True, so we will return 1.

 Output :
 1

 Constraints:
1 <= T <= 10
3 <= |‘EXP’| <= 200    
Where |EXP| denotes the length of 'EXP'.
Time Limit: 1 sec

Sample Input 1 :
T&T
T^T^F    

Sample Output 1 :
1
0

Explanation For Sample Input 1:
For the first test case:
There is only one  way to parenthesize this expression:
(T&T) = T
So we will return 1.

For the second test case:
There are total 2  ways to parenthesize this expression:
(i) (T^T)^(F) = F
(ii) (T)^(T^F) = F
Both the ways will result in False, so we will return 0.

Sample Input 2 :
F|T^F
F&T

Sample Output 2 :
2
0

Explanation For Sample Input 2:
For the first test case:
There are total 2  ways to parenthesize this expression:
(i) (F|T)^(F) = T
(ii) (F)|(T^F) = T
Both the ways will result in True, so we will return 2.

For the second test case:
There is only one  way to parenthesize this expression:
(F&T) = F
So we will return 0.

*/


//RECURSION
#include<bits/stdc++.h>
int mod=1e9+7;

int f(int i, int j, int isTrue, string &exp){
    if(i>j)
        return 0;
    if(i==j){
        if(isTrue){
            return exp[i]=='T';
        }
        else{
            return exp[i]=='F';
        }
    }
    long long ways=0;
    for(int idx=i+1;idx<=j-1;idx++){
        long long LT = f(i,idx-1,1,exp);
        long long LF = f(i,idx-1,0,exp);
        long long RT = f(idx+1,j,1,exp);
        long long RF = f(idx+1,j,0,exp);
        
        if(exp[idx] == '&'){
            if(isTrue)
                ways = (ways + (RT*LT)%mod)%mod;
            else
                ways = (ways + (RT*LF)%mod + (RF*LT)%mod + (RF*LF)%mod)%mod;
        }
        
        
        else if(exp[idx] == '|'){
            if(isTrue)
                ways = (ways + (LT*RT)%mod + (LT*RF)%mod + (LF*RT)%mod)%mod;
            
            else
                ways = (ways + (LF*RF)%mod)%mod;
        }
        
        
        else{
            if(isTrue)
                ways = (ways + (LT*RF)%mod + (LF*RT)%mod)%mod;
            else
                ways = (ways + (LF*RF)%mod + (LT*RT)%mod)%mod;
        }
    }    
    return ways;
    
}

int evaluateExp(string & exp) {
    return f(0,exp.size()-1,1,exp);
}


//MEMOIZATION

int f(int i, int j, int isTrue, string &exp, vector<vector<vector<int>>> &dp){
    if(i>j)
        return 0;
    if(i==j){
        if(isTrue){
            return exp[i]=='T';
        }
        else{
            return exp[i]=='F';
        }
    }
    
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    long long ways=0;
    for(int idx=i+1;idx<=j-1;idx++){
        long long LT = f(i,idx-1,1,exp,dp);
        long long LF = f(i,idx-1,0,exp,dp);
        long long RT = f(idx+1,j,1,exp,dp);
        long long RF = f(idx+1,j,0,exp,dp);
        
        if(exp[idx] == '&'){
            if(isTrue)
                ways = (ways + (RT*LT)%mod)%mod;
            else
                ways = (ways + (RT*LF)%mod + (RF*LT)%mod + (RF*LF)%mod)%mod;
        }
        
        
        else if(exp[idx] == '|'){
            if(isTrue)
                ways = (ways + (LT*RT)%mod + (LT*RF)%mod + (LF*RT)%mod)%mod;
            
            else
                ways = (ways + (LF*RF)%mod)%mod;
        }
        
        
        else{
            if(isTrue)
                ways = (ways + (LT*RF)%mod + (LF*RT)%mod)%mod;
            else
                ways = (ways + (LF*RF)%mod + (LT*RT)%mod)%mod;
        }
    }    
    return dp[i][j][isTrue] = ways;
    
}

int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return f(0,exp.size()-1,1,exp,dp);
}


//TABULATION
int evaluateExp(string & exp) {
    int n= exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, 0)));
    
    for(int i=0; i<n; i++){
        dp[i][i][1] = (exp[i] == 'T');
        dp[i][i][0] = (exp[i] == 'F');
    }
    
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            for(int isTrue=0; isTrue <=1; isTrue++){
                ll ways=0;
                for(int ind =i+1; ind <= j-1; ind=ind+2){
                    ll lT = dp[i][ind-1][1];
                    ll lF = dp[i][ind-1][0];
                    ll rT = dp[ind+1][j][1];
                    ll rF = dp[ind+1][j][0];
                    if(exp[ind] == '&'){
                        if(isTrue) ways = (ways + (lT * rT)%mod)%mod;
                        else ways = (ways + (lT*rF)%mod + (lF*rF)%mod + (lF*rT)%mod)%mod;
                    }
                    else if(exp[ind] == '|'){
                        if(isTrue) ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
                        else ways = (ways + (lF*rF)%mod)%mod;
                    }
                    else{
                        if(isTrue) ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
                        else ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    
    return dp[0][n-1][1];
}
#include<bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int> & dp){
	if(n<=1){//base case
		return n;
	}

	if(dp[n]!=-1){//memoization step
		return dp[n];
	}

	return dp[n]=fibo(n-1, dp)+fibo(n-2, dp);
}


//TIME: O(N) N-> for deeper calls from 5 to n f(5)->f(4)->f(3)->f(2)->f(1) these are
//calls on the left side of recursion tree and rest calls on right can be done in 
//constant time using memoization
//SPACE: O(N){for Array dp[] } + O(N){for Recursion Stack space}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


int n;
cin>>n;
// int dp[n+1];
// memset(dp,-1,sizeof dp);
//cout<<fibo(n,dp)<<endl;

vector<int>dp(n+1,-1);
cout<<fibo(n,dp)<<endl;

return 0;
}
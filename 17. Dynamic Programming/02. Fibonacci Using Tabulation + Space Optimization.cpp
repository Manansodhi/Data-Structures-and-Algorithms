#include<bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	
//Tabulation
//TIME: O(N) for loop
//SPACE: O(N)for Array space dp[]
 
	int dp[n+1];
	//base case
	dp[0]=0;
	dp[1]=1;

	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2]
	}


//More Space Optimized PAttern Obseravation
//TIME: O(N) for loop
//SPACE: O(1)

int n;
cin>>n;
int prev2=0;
int prev=1;
for(int i=2;i<=n;i++){
	int curri = prev + prev2;
	prev2=prev;
	prev=curri;
}

cout<<prev<<endl;


return 0;
}
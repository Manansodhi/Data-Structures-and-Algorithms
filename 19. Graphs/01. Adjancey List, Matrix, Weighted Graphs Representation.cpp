#include<bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

int n,m;
cin>>n>>m;

//ADJANCEY MATRIX 
//SPACE O(N^2)
int adj[n+1][n+1];
for(int i=0;i<m;i++){
	int u,v;
	cin>>u>>v;

	adj[u][v]=1;
	adj[v][u]=1;
//if Graph is Directed then remove 2nd line adj[v][u]=1
}

//ADJANCEY LIST
//SPACE O(N+2*E)

vector<int>adj[n+1]
for(int i=0;i<m;i++){
	int u,v;
	cin>>u>>v;

	adj[u].push_back(v);
	adj[v].push_back(u);
	//if Graph is Directed then remove 2nd line adj[v].push_back(u);

}

//If Graph is Weighted then
vector<pair<int,int>> adj[n+1];   
//first int of pair will hold the adjacent node and second int will hold the weight of edge btw the 2 nodes

for(int i=0;i<m;i++){
	int u,v,wt;
	cin>>u>>v>>wt;

	adj[u].push_back({v,w});
	adj[v].push_back({u,w});
}



	return 0;
}
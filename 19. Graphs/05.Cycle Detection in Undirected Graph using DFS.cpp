#include<bits/stdc++.h>
using namespace std;

bool checkForCycleDFS(int node, int prev, vector<int> adj[], vector<int> &visited){
	visited[node]=1;
	for(auto it:adj[node]){
		if(visited[it]){
			if(checkForCycleDFS(it,node,adj,visited))
				return true;
		}
		else if(it!=prev)
			return true;
	}
	return false; 
}


bool isCycle(int noNodes, vector<int> adj[]){
	vector<int>visited(noNodes+1, 0);
	for(int i=0;i<noNodes;i++){
		if(!visited[i]){
			if(checkForCycleDFS(i,-1,adj,visited))
				return true;
		}
	}
	return false;
}





int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

int n,m;
cin>>n>>m;
vector<int>adj[n+1];
for(int i=0;i<m;i++){
	int u,v;
	cin>>u>>v;

	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool ans = isCycle(n,adj);

cout<<ans;

cout<<endl;

return 0;
}

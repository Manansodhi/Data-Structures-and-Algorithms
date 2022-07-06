#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &ans){
	ans.push_back(node);
	visited[node]=1;
	for(auto it:adj[node]){
		if(!visited[it]){
			dfs(it,visited,adj,ans);
		}
	}
}


vector<int> DFSofGraph(int noNodes, vector<int> adj[]){
	vector<int>ans;
	vector<int>visited(noNodes+1, 0);

	for(int i=1;i<=noNodes;i++){
		if(!visited[i]){
			dfs(i,visited,adj,ans);
		}
	}
	return ans;

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

vector<int> ans = DFSofGraph(n,adj);

for(auto it:ans)
	cout<<it<<",";

cout<<endl;

return 0;
}

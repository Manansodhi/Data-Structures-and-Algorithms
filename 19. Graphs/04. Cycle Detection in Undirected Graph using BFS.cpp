#include<bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, int noNodes, vector<int> adj[], vector<int> &visited){
	queue<pair<int,int>> q;
	visited[node]=1;
	s.push({node,-1});

	while(!q.empty()){
		int nn=q.front().first;
		int perv = q.front().second
		q.pop();

		for(auto it:adj[node]){
			if(!visited[it]){
				visited[it]=1;
				q.push({it,nn});
			}
			else if(prev != it){
				return true;
			}
		}
		return false;
	}
}


bool isCycle(int noNodes, vector<int> adj[]){
	vector<int>visited(noNodes+1, 0);
	for(int i=0;i<noNodes;i++){
		if(!visited[i]){
			if(checkForCycle(i,noNodes,adj,visited))
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

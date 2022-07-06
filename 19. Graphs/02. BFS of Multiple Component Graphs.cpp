#include<bits/stdc++.h>
using namespace std;

vector<int> bfsofGraph(int noNodes, vector<int> adj[]){
	vector<int>bfs;
	vector<int>visited(noNodes+1, 0);

	for(int i=1;i<=noNodes;i++){
		if(!visited[i]){
			queue<int>q;
			q.push(i);
			visited[i]=1;
			while(!q.empty()){
				int node=q.front();
				q.pop();
				bfs.push_back(node);

				for(auto it:adj[node]){
					if(!visited[it]){
						q.push(it);
						visited[it]=1;
					}
				}
			}
		}
	}
	return bfs;
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

vector<int> ans = bfsofGraph(n,adj);

for(auto it:ans)
	cout<<it<<",";

cout<<endl;

return 0;
}



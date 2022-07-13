// #include<bits/stdc++.h>
// using namespace std;

// vector<int> bfsofGraph(int noNodes, vector<int> adj[]){
// 	vector<int>bfs;
// 	vector<int>visited(noNodes+1, 0);

// 	for(int i=1;i<=noNodes;i++){
// 		if(!visited[i]){
// 			queue<int>q;
// 			q.push(i);
// 			visited[i]=1;
// 			while(!q.empty()){
// 				int node=q.front();
// 				q.pop();
// 				bfs.push_back(node);

// 				for(auto it:adj[node]){
// 					if(!visited[it]){
// 						q.push(it);
// 						visited[it]=1;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return bfs;
// }


// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// int n,m;
// cin>>n>>m;
// vector<int>adj[n+1];
// for(int i=0;i<m;i++){
// 	int u,v;
// 	cin>>u>>v;

// 	adj[u].push_back(v);
// 	adj[v].push_back(u);
// }

// vector<int> ans = bfsofGraph(n,adj);

// for(auto it:ans)
// 	cout<<it<<",";

// cout<<endl;

// return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &ans){
// 	ans.push_back(node);
// 	visited[node]=1;
// 	for(auto it:adj[node]){
// 		if(!visited[it]){
// 			dfs(it,visited,adj,ans);
// 		}
// 	}
// }


// vector<int> DFSofGraph(int noNodes, vector<int> adj[]){
// 	vector<int>ans;
// 	vector<int>visited(noNodes+1, 0);

// 	for(int i=1;i<=noNodes;i++){
// 		if(!visited[i]){
// 			dfs(i,visited,adj,ans);
// 		}
// 	}
// 	return ans;
// }


// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// int n,m;
// cin>>n>>m;
// vector<int>adj[n+1];
// for(int i=0;i<m;i++){
// 	int u,v;
// 	cin>>u>>v;

// 	adj[u].push_back(v);
// 	adj[v].push_back(u);
// }

// vector<int> ans = DFSofGraph(n,adj);

// for(auto it:ans)
// 	cout<<it<<",";

// cout<<endl;

// return 0;
// }

#include<bits/stdc++.h>
using namespace std;

bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
    {
        // Create a queue for BFS
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
 
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V - 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, V, adj, vis))
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

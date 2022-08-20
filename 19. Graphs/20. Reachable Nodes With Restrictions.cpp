class Solution {
public:
    void dfs(vector<int> adj[],vector<int>& visited,vector<int>& restricted,vector<int>& temp,int s)
    {
        
        visited[s]=1;
        temp.push_back(s);
        //cout<<s<<" ";
        for(int i=0;i<adj[s].size();i++)
        {
            if(!visited[adj[s][i]])
            {
                dfs(adj,visited,restricted,temp,adj[s][i]);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> visited;
        for(int i=0;i<n+1;i++)
        {
            visited.push_back(0);
        }
        vector<int> adj[n+1];
        for(int i=0;i<edges.size();i++)
        {
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<restricted.size();i++)
        {
            visited[restricted[i]]=1;
        }
        vector<int> temp;
        dfs(adj,visited,restricted,temp,0);
        return temp.size();
        
    }
};



class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> vis(n,0);
        vector<int> adj[n];
        unordered_map<int,int> mp;
        
        for(auto i:restricted){
            mp[i]++;
        }
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        int count=0;
        queue<int> q;
        q.push(0);
        vis[0]=1;
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(auto i: adj[node]){
                if(!vis[i] && mp[i]==0){
                    count++;
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        
        return count+1;
    }
};


class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> rest(restricted.begin(), restricted.end());
        
        vector<int> adj[n];
        vector<int> visited(n, false);
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int ans = 1;
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            
            
            for(auto v: adj[u]) {
                if(visited[v] == false && rest.count(v) == 0) {
                    visited[v] = true;
                    q.push(v);
                    ans++;
                    // cout<<v<<" ";
                }
            }
        }
        return ans;
    }
};
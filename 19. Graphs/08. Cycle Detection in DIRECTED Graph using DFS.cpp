/*
Alternate way  : 3 states can be used inside the visited array itself, 0 -> indicates not visited at all | 1 -> indicates node visited but not in current traversal | 2 -> indicates visited earlier as well in current traversal (cycle present)


bool dfsCycle (int u, vector<int>& vis, vector<bool>& dfsvis, vector<vector<int>>& adj) {
        
        // states : 0 -> Not Visited | 1 -> visited | 2 -> visited + visited in current traversal
        
        // vis[u] = true ; 
        // dfsvis[u] = true ;
        
        vis[u] = 2 ; // same as upper 2 stmts 
        
        for (auto &it: adj[u]) 
        {
            if (!vis[it]) 
            {
                if (dfsCycle(it, vis, dfsvis, adj)) 
                    return true ;
            }
            else if (vis[it] == 2)
                return true ; 
        }
        
        vis[u] = 1 ;  // same as  dfsvis[u]  = false 
        return false ; 
        
    }


    2 arrays of boolena is equal to one array of integers, hence its equivalent 
    */



bool cycle_directed(int node,vector<int> &visited,vector<int> &dfs_visited)
{
	visited[node]=1;
	dfs_visited[node]=1;
	for(auto it:g[node])
	{
		if(!visited[it])
		{
			if(cycle_directed(it,visited,dfs_visited))
			return true;
		}
		else if(dfs_visited[it])
		return true;
	}
	dfs_visited[node]=0;
	return false;
}
bool check_cycle_directed_DFS()
{
	vector<int> visited(g.size()+1,0);
	vector<int> dfs_visited(g.size()+1,0);
	for(int i=1;i<=g.size();i++)
	{	
		if(!visited[i])
		{
		if(cycle_directed(i,visited,dfs_visited))
		return true;
		}
	}
	return false;
}
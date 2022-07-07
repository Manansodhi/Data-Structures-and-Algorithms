
void findTopologicalSort(int node, vector<int>&visited, stack<int>&st, vector<int>adj[]){
	visited[node]=1;
	for(auto it:adj[node]){
		if(!visited[it])
			findTopologicalSort(it,visited,st,adj);
	}
	st.push(node);
}



vector<int>toplogicalSort(int n, vector<int>adj[]){
	stack<int>st;
	vector<int>visited(n,0);
	for(int i=o;i<n;i++){
		if(!visited[i]){
			findTopologicalSort(i,visited,st,adj);
		}
	}
	vector<int>topo;
	while(!st.empty()){
		topo.push_back(st.top());
		st.pop();
	}
	return topo;
}
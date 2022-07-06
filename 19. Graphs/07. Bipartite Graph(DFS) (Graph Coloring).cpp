



bool bipartiteDFS(int node, vector<int>adj[], int color[]){
	if(color[node] == -1)
		color[node]=1;

	for(auto it:adj){
		if(color[it] == -1){
			color[it] = 1-color[node];
			if(!bipartiteDFS(it,adj,color)){
				return false;
			}
			else f(color[it] == color[node]){
				return false;
			}
		}
	}
	return true;
}




bool checkBipartite(vector<int> adj[], int noNodes){
	int color[noNodes];
	memset(color,-1,sizeof(color));
	for(int i=0;i<noNodes;i++){
		if(color[i]==-1){
			if(!bipartiteDFS(i,adj,color)){
				return false;
			}
		}
	}
	return true;
}
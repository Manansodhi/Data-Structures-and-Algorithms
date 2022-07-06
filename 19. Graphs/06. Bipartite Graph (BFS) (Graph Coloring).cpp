

bool bipartiteBFS(int node, vector<int>adj[], int color[]){
	queue<int>q;
	q.push(node);
	color[node]=1;
	while(!q.empty()){
		int nn=q.front();
		q.pop();

		for(auto it:adj[nn]){
			if(color[it]==-1){
				color[it] = 1-color[nn];
				q.push(it);
			}
			else if(color[it]==color[nn]){
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
			if(!bipartiteBFS(i,adj,color)){
				return false;
			}
		}
	}
	return true;
}
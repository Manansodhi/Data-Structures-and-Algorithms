

bool isCyclic(int n,vector<int> adj[]){
	queue<int>q;
	vector<int>inDegree(n,0);
	for(int i=0;i<n;i++){
		for(auto it:adj[i]){
			inDegree[it]++;
		}
	}	

	for(int i=0;i<n;i++){
		if(inDegree[i]==0)
			q.push(i);
	}

	int count=0;
	while(!q.empty()){
		q.pop();
		count++;
		for(auto it:adj[node]){
			inDegree[it]--;
			if(inDegree[it]==0){
				q.push(it);
			}
		}
	}

	//if we are able to generate topo sort then coun will be equal to n topo generated means 
	//it DAG(directed Acyclic graph) so graphi not cyclic and return false
	if(count==n)
		return false;
	return true;
}

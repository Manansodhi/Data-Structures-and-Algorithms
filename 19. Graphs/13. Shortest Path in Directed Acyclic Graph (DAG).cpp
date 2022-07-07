
void findTopologicalSort(int node, int visited[], stack<int> &st, vector<pair<int,int>> adj[]){
	visited[node]=1;
	for(auto it:adj[node]){
		if(!visited[it.first])
			findTopologicalSort(it.first,visited,st,adj);
	}
	st.push(node);
}


void shortestPath(int src, int n, vector<pair<int,int>> adj[]){
	int visited[n] = {0};
	stack<int>st;
	for(int i=0;i<n;i++){
		if(!visited[i])
			findTopologicalSort(i,visited,st,adj);
	}


	int distance[n];
	for(int i=0;i<n;i++){
		distance[i]=1e9;
	}
	distance[src]=0;


	while(!st.empty()){
		int node=st.top();
		st.pop();

		//if the node has been reached previously or not if it had reached it previously 
		//then it cannot go its adjacent nodes again
		if(distance[node] != INF){
			for(auto it:adj[node]){
				if(distance[node] + it.second < distance[it.first]){
					distance[it.first] = distance[node]+it.second;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		(distance[i] == 1e9)?cout<<"INF" : cout<<distance[i]<<" ";
	}

}



int main(){
	int n,m;
	cin>>n>>m;
	vctor<pair<int,int>> adj[n];
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
	}

	shortestPath(0,n,adj);

	return 0;
}
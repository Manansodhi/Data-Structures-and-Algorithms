
cin>>source;

priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> pq;
vector<int>dist(n+1, INT_MAX);

dist[src]=0;
pq.push(make_pair(0,src));

while(!pq.empty()){
	int prev_dist = pq.top().first;
	int prev_node = pq.top().second;
	pq.pop();

	for(auto it:adj[prev_node]){
		int next_node = it->first;
		int next_dist = it->second;

		if(dist[prev_node]+next_dist < dist[next_node]){
			dist[next_node]=dist[prev_node]+next_dist;
			pq.push(make_pair(dist[next_node],next_node));
		}
	}
}

for(int i=1;i<=n;i++)
	cout<<dist[i]<<" "

cout<<endl;
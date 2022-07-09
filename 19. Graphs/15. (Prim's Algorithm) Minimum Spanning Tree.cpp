#include<bits/stdc++.h>
using namespace std;


//BRUTE FORCE APPROCH 
//TIME:- greater than O(N^2))
//APCE:- O(N+E)+ 3*O(N) for 3 array of size N

// int main(){
// 	int N,m;
// 	cin>>N>>m;
// 	vector<pair<int,int>> adj[N];

// 	int a,b,wt;
// 	for(int i=0;i<m;i++){
// 		cin>>a>>b>>wt;
// 		abj[a].push_back(make_pair(b,wt));
// 		abj[b].push_back(make_pair(a,wt));
// 	}

// 	int parent[N], key[N], mst[N];

// 	for(int i=0;i<N;i++)
// 	key[i]=INT_MAX, mst[i]=false,parent[i]=-1;

	
// 	key[0]=0;
// 	for(int count=0;count<N-1;count++){
// 		int mini = INT_MAX, idx;

// 		for(int i=0;i<N;i++)
// 			if(mst[i]==false && key[i]<mini)
// 				mini=key[i],idx=i;
		

// 		mst[idx]=true;
// 		for(auto it:adj[u]){
// 			int adjNode = it.first;
// 			int edgeWeight = it.second;
// 			if(mst[adjNode]==false &&  edgeWeight<key[adjNode])
// 				parent[adjNode]=idx, key[adjNode]=edgeWeight;
// 		}
// 	}
// 	for(int i=1;i<n;i++)
// 		cout<<parent[i]<<"->"<<i<<endl;

// 	return 0;
// }



//OPTIMIZED APPROCH
//Using priority Queue to find minimum element in log N instead of using for loop
int main(){
	int N,m;
	cin>>N>>m;
	vector<pair<int,int>> adj[N];

	int a,b,wt;
	for(int i=0;i<m;i++){
		cin>>a>>b>>wt;
		abj[a].push_back(make_pair(b,wt));
		abj[b].push_back(make_pair(a,wt));
	}

	int parent[N], key[N], mst[N];

	for(int i=0;i<N;i++)
	key[i]=INT_MAX, mst[i]=false,parent[i]=-1;

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	
	key[0]=0;
	//{0,0} -> key,indx
	pq.push({0,0});
	for(int count=0;count<N-1;count++){
		int idx = pq.top().second();
		pq.pop();
		

		mst[idx]=true;
		for(auto it:adj[idx]){
			int adjNode = it.first;
			int edgeWeight; = it.second;
			if(mst[adjNode]==false &&  edgeWeight<key[adjNode]){
				parent[adjNode]=idx;
				pq.push({key[adjNode], adjNode});
				key[adjNode]=edgeWeight;
			}
		}
	}
	for(int i=1;i<n;i++)
		cout<<parent[i]<<"->"<<i<<endl;

	return 0;
}
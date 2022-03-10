#include<bits/stdc++.h>
using namespace std;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	list<pair<int,int> >*l; //dynamic list (to get input from user for number of vertexes and we have to create array of linked list)
	int n; //No of vertices
	cin>>n;
	l = new list<pair<int,int> > [n]; //creating a new array depending on number of vertices inputed to store connection between edge and its distence(weight) from that

	int e; //No of edges
	cin>>e;
	//loop for taking input of edges(connection) between vertexes and its corresponding weight(distance)
	for(int i =0;i<e;i++){
		int x,y,wt;
		cin>>x>>y>>wt;

		l[x].push_back(make_pair(y,wt)); // forward egde (uni-directional)
		l[y].push_back(make_pair(x,wt)); // reverse egde (bi-directinal)

	}

	//printing linked list
	for(int i=0;i<=n;i++){
		cout<<"linked list " << i <<"-->";
		//every element of linked list is going to be pair of 2nd edge and distance between them
		for(auto xp:l[i]){
			cout <<"("<<xp.first<<", "<<xp.second <<"), ";
		}
		cout<<endl;
	}




	return 0;

}
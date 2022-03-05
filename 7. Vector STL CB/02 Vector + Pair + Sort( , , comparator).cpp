#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>c1,pair<int,int>c2){
	int d1=c1.first*c1.first + c1.second*c1.second;
	int d2=c2.first*c2.first + c2.second*c2.second;

	//if two cabs have same distance from origin then sort according to x-coordinate
	if(d1==d2){
		return c1.first<c2.first;
	}
	else{
		return d1<d2;
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}

	sort(v.begin(),v.end(),compare);

	for(auto x:v){
		cout<<x.first <<" " <<x.second;
	}
	cout<<endl;

	return 0;
}
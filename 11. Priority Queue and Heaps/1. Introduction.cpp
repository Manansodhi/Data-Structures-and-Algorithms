#include<bits/stdc++.h>
using namespace std;


int main() {
	priority_queue<int>pq_max; //by default it is max heap means max value has max priority
	priority_queue<int, vector<int>, greater<int> > pq_min; //it is min heap;

	int nElement;
	cin>>nElement;
	for(int i=1;i<=nElement;i++){
		int no;cin>>no;
		pq_max.push(no); //push() takes O(LogN)
		pq_min.push(no);
	}

	//remove elements from heap
	while(!pq_max.empty()){
		cout<<pq_max.top()<<" ";	//top()-> O(1)
		pq_max.pop();	//pop()-> O(LogN)
	}
	cout<<endl;

	//remove elements from heap
	while(!pq_min.empty()){
		cout<<pq_min.top()<<" ";	//top()-> O(1)
		pq_min.pop();	//pop()-> O(LogN)
	}


	return 0;

}

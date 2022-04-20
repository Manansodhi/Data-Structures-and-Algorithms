#include<bits/stdc+.h>
using namespaace std;


int main(){
	
	priority_queue<int>leftheap; //max Heap
	priority_queue<int,vector<int>,greater<int>>rightheap; //min heap

	int d;
	cin>>d;
	leftheap.push(d);
	float median=d;
	cout<<median<<" ";
	cin>>d;
	while(d!=-1){
		if(leftheap.size() > rightheap.size()){
		//as esme size unequal (odd) h heap ka toh jabnew element push karege toh even number of element ho 
		//jayege toh median average to 2 middle number hoga
			if(d<median){
				//eska matlab h ki jo d element h voh leftheap m jana chahiye becoz voh chota h median se bhut
				//leftheap phele se size m badi h toh rebalancing hogi phele
				rightheap.push(leftheap.top());
				leftheap.pop();
				leftheap.push(d);
			}
			else{
				rightheap.push(d);
			}
			median=(leftheap.top()+rightheap.top())/2;
		}
		else if(leftheap.size()==rightheap.size()){
			if(d<median){
				leftheap.push(d);
				median=leftheap.top();
			}
			else{
				rightheap.push(d);
				median=rightheap.top();
			}
		}
		else{
			//leftheap.size()<rightjheap.size()
			if(d<median){
				leftheap.push(d);
			}
			else{
				leftheap.push(rightheap.top());
				rightheap.pop();
				rightheap.push(d);
			}
			median=(leftheap.top()+rightheap.top())/2;
		}
		cout<<median<<" ";
		cin>>d;
	}


	return 0;
}
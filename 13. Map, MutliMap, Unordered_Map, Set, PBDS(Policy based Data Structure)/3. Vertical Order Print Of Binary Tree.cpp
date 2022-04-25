#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data=d;
		left=right=NULL;
	}
};
//we will maintain hashmap in which each node will conatin key and also contain vetcor. traversing tree and 
//storing key & values 

//by default stl container are passed by value but we only want to make one container through out and
//make changes to original one only so we pass by reference 

void verticalOrderPrint(node*root, int distance, map<int, vector<int> >&m){

	//base case
	if(root == NULL){
		return;
	}
	m[d].push_back(root->data);
	verticalOrderPrint(root->left, d-1, m);
	verticalOrderPrint(root->right, d+1, m);

	return;

}



int main(){

    node*root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    root->right->right->right = new node(9);

    root->left->right->right = new node(8);

    map<int, vector<int> > m;
    int distance = 0;
    verticalOrderPrint(root,distance,m);

    for(auto p:m){
       // cout<<p.first<<"->";
        for(int x:p.second){
            cout<<x<<",";
        }
        cout<<endl;
    }

return 0;
}

vector<int>InorderTraversal(Node* root){
	stack<Node*>st;
	Node* node=root;
	vector<int>inorder;

	while(true){
		if(node!=NULL){
			st.push(node);
			node=node->left;
		}
		else{
			if(st.empty()){
				break;
			}
			node=st.top();
			st.pop();
			inorder.push_back(node->data);
			node=node->right;
		}
	}
	return inorder;
} 
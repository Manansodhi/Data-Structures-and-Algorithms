
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data=val;
		left=right=NULL;
	}
};


void LevelOrder(Node* root){
	vector<vector<int>> ans;
	if(root == NULL)
		return ans;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		int size=q.size();
		vector<int>level;
		for(int i=0;i<size;i++){
			Node* node=q.front();
			q.pop();
			if(node->left != NULL)
				q.push(node->left);
			if(node->right != NULL)
				q.push(node->right);
			level.push_back(node->data);
		}
		ans.push_back(level);
	}
	return ans;
}


int main(){
	struct Node* root = new node(1);
	 root->left = new node(2);
	 root->right = new node(3);
	 root->left->left = new node(4);
	 root->left->right = new node(5);
}
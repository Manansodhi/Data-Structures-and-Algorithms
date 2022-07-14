
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data=val;
		left=right=NULL;
	}
};


void preOrder(Node* root){
	if(root == NULL)
		return;

	cout<<root->data<", ";
	preOrder(root->left);
	preOrder(root->right);
}


int main(){
	struct Node* root = new node(1);
	 root->left = new node(2);
	 root->right = new node(3);
	 root->left->left = new node(4);
	 root->left->right = new node(5);
}
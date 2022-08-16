

LCA(root, p, q){
	if(root==NULL)
		return NULL;
	int curr=root->val;
	if(curr < p->val && curr < q->val)
		return LCA(root->right,p,q);
	if(curr > p->val && curr > q->val)
		return LCA(root->left,p,q);
}
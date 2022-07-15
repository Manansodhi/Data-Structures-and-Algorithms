
/*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values.
(i.e., from left to right, level by level from leaf to root).

 
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/


/*Main CATCH of this code is that you dont need to reverse the vector in last.
We can smartly just use our depth function to save ourself few fraction of our computation energy.

Used queue and iterative method to do the level order traversal.
I calculated depth first to know the level so that we dont need to reverse the vector at the end.
Rest is a simple code starting from bottom I am inserting vector entries.*/


//1.Approch 1rst code
class Solution {
public:
    int depth(TreeNode* root){
        if(root == NULL)return 0;
		//return the maximum depth of the tree so to find the levels
        return max(depth(root->right),depth(root->left))+1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
     if(root == NULL)return {};
        int d = depth(root);
		//initialise the empty levels inside a vector
        vector<vector<int> > level(d,vector<int>({})); 
        int i = 0;
		//use a queue to maintain the tree nodes
        queue<TreeNode*> q;
		//push the root node with one element and decrement the level
        q.push(root);
        level[d-1].push_back(root->val);
        q.push(NULL);
        d--;

		// do work while queue is not empty
        while(!q.empty()){
			// extract the node from the queue and remove it from the queue
            TreeNode* temp = q.front();
            q.pop();
            
			//if the node exist check its right and left node
            if(temp){  
				// and if the left and right node exist simply push the value to the vector
                if(temp->left){
                        q.push(temp->left);
                        level[d-1].push_back(temp->left->val);
                    }    
                if(temp->right){
                        q.push(temp->right);
                        level[d-1].push_back(temp->right->val);
                    }
            }                 
            else {
			// to handle condition if NULL found at a node
                if(q.empty()) break;
                d--;
                q.push(NULL);
            }  
        }
		// now without reversing the vector you can simply return the answer
        return level;
    }
};


//1.Approch 2nd code
int depth(TreeNode *root) {
    if (!root) return 0;
    return max(depth(root->left),depth(root->right))+1;
}

void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
    if (!node) return;
    ans[level].push_back(node->val);
    levelOrder(ans,node->left,level-1);
    levelOrder(ans,node->right,level-1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int d = depth(root);
    vector<vector<int>> ans(d,vector<int> {});
    levelOrder(ans,root,d-1);
    return ans;
}


//2.Approch 1rst code
void LevelOrder(Node* root, vector<vector<int>> &ans){
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
}
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    levelOrder(ans,root);
    reverse(ans.begin(),ans.end());
    return ans;
}
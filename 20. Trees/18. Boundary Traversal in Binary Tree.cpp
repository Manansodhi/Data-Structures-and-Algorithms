/*
You have been given a binary tree of integers. Your task is to print the boundary nodes of this 
binary tree in Anti-Clockwise direction starting from the root node.
NOTE:
The boundary nodes of a binary tree include nodes from the left boundary, right boundary and the 
leaf nodes without duplicate nodes. However, the values from the nodes may contain duplicates. 
Constraints:
1 <= T <= 10^2
1 <= N <= 2^12 

Where 'N' is the total number of nodes in the binary tree.


Sample Input 1:
2
1 2 3 4 -1 5 -1 -1 -1 -1 -1
1 2 -1 3 -1 4 -1 -1 -1

Sample Output 1:
1 2 4 5 3 
1 2 3 4

Explanation Of Sample Input 1:
For the first test case, we have 1 as the root node. 2, 4 as left boundary nodes. 3, 5 as the 
right boundary nodes. We don't have any leaf nodes.

For the second test case, we have 1 as the root node. 2, 3 as the left boundary nodes and 4 as a
leaf node. We don't have any right boundaries.


/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isleaf(TreeNode<int>* root){
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode<int>* root, vector<int>& res){
    TreeNode<int>* curr = root->left;
    while(curr){
        if(!isleaf(curr))
            res.push_back(curr->data);
        if(curr->left)
            curr=curr->left;
        else
            curr=curr->right;
    }
}

void addLeaves(TreeNode<int>* root, vector<int> &res){
    if(isleaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if(root->left)
        addLeaves(root->left,res);
    if(root->right)
        addLeaves(root->right,res);
}

void addRightBoundary(TreeNode<int>* root, vector<int>&res){
    TreeNode<int>* curr=root->right;
    vector<int>tmp;
    while(curr){
        if(!isleaf(curr))
            tmp.push_back(curr->data);
        if(curr->right)
            curr=curr->right;
        else
            curr=curr->left;
    }
    for(int i=tmp.size()-1;i>=0;i--){
        res.push_back(tmp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>res;
    if(!root)
        return res;
    
    if(!isleaf(root))
        res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}
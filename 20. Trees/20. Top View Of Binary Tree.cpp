/*
Top View Of Binary Tree

You are given a Binary Tree of integers. You are supposed to return the top view of the given 
binary tree. The Top view of the binary tree is the set of nodes that are visible when we see 
the tree from the top.


        1
      /   \
     2      3
    /  \     \
  4     5     7
       /             
      6        


top view of this tree will be ==> 4,2,1,3,7 


*/

vector<int> getTopView(TreeNode<int> *root) {
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>map;
    queue<pair<TreeNode<int> *,int>>q;
    q.push({root,0});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode<int> *node=it.first;
        int line=it.second;
        
        if(map.find(line) == map.end()){
            map[line] = node->val;
        }
        
        if(node->left != NULL)
            q.push({node->left, line-1});
        if(node->right != NULL)
            q.push({node->right, line+1});
    }
    
    for(auto it:map)
        ans.push_back(it.second);
    
    return ans;
}
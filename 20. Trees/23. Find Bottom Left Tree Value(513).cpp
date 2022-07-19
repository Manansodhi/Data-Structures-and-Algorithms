/*

513. Find Bottom Left Tree Value
Given the root of a binary tree, return the leftmost value in the last row of the tree.

        1
      /   \
     2     3 
    /     / \
  4      5   6
        /           
       7   

       Bottom Left Tree Value ==> 7
 */

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
      int ans ;
        if(root == NULL)
          return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
          int size=q.size();
          for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->right != NULL)
              q.push(node->right);
            if(node->left != NULL)
              q.push(node->left);
            ans=node->val;
          }
          
        }
        return ans;
    }
  
};

/*
1302. Deepest Leaves Sum

Given the root of a binary tree, return the sum of values of its deepest leaves.
 
Example 1:
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15 (deeplest leaves are 7 & 8 sum=> 7+8=> 15)

        1
      /   \
     2      3
    /  \     \
  4     5     6
 /             \
7               8

Example 2:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100
 */
class Solution {
public:
  
  int high,ans;
  
  void cal(TreeNode *root,int level){
    if(root==NULL)
      return;
    
    cal(root->left,level+1);
    cal(root->right,level+1);
    
    if(level>high){
      high=level;
      ans=root->val;
    }
    else if(level==high){
      ans+=root->val;
    }
  }
  
  
    int deepestLeavesSum(TreeNode* root) {
      high=0;
      ans=0;
      cal(root,0);
      return ans;
    }
};
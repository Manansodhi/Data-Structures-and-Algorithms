/* 
814. Binary Tree Pruning

Given the root of a binary tree, return the same tree where every subtree (of the given tree) 
not containing a 1 has been removed.
A subtree of a node node is node plus every node that is a descendant of node.

 
Example 1:
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]

Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

Example 2:
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Example 3:
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
 
Constraints:
The number of nodes in the tree is in the range [1, 200].
Node.val is either 0 or 1.

*/

class Solution {
public:
  
  int helper(TreeNode* root){
    if(root==NULL){
      return 0; //0--> is the number of 1's in subtree agar root==null h no of 1's toh 0 hi hoge
    }
    
    if(root->left == NULL && root->right == NULL){
      if(root->val == 0){
        return 0;  //0--> is the number of 1's in subtree
      }
      else{
        return 1; //1--> is the number of 1's in subtree
      }
    }
    
    int leftSubtreeOnes = helper(root->left);
    int rightSubtreeOnes = helper(root->right);
    
    if(leftSubtreeOnes == 0){
      root->left = NULL;
    }
    if(rightSubtreeOnes == 0){
      root->right = NULL;
    }
    
    return leftSubtreeOnes + rightSubtreeOnes + (root->val == 1 ? 1:0);
  }
  
    TreeNode* pruneTree(TreeNode* root) {
      //ye wala if us ke liye agar puree tree m ek bhi 1 na ho sirf null return karna hoga
        if(helper(root) == 0)
          return NULL;
      
      return root;
    }
  
};
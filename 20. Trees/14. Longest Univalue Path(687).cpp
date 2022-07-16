/*
687. Longest Univalue Path

Given the root of a binary tree, return the length of the longest path, where each node in the 
path has the same value. This path may or may not pass through the root.
The length of the path between two nodes is represented by the number of edges between them.

 
Example 1:
Input: root = [5,4,5,1,1,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 5).

Example 2:
Input: root = [1,4,5,4,4,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 4).
 
Constraints:
The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
The depth of the tree will not exceed 1000.
 */

class Solution {
public:
  
  int UniPathLen(TreeNode* root, int &len){
    if(root == NULL)
      return 0;
    
    int leftLen = UniPathLen(root->left,len);
    int rightLen = UniPathLen(root->right,len);
    int leftcheck=0,rightcheck=0;
    
    if(root->left != NULL && root->val == root->left->val)
      leftcheck = leftLen+1;
    if(root->right != NULL && root->val == root->right->val)
      rightcheck = rightLen+1;
    
    len = max(len, leftcheck+rightcheck);
    
    return max(leftcheck,rightcheck);
  }
  
    int longestUnivaluePath(TreeNode* root) {
      int Len=0;
      UniPathLen(root,Len);
      return Len;
    }
};
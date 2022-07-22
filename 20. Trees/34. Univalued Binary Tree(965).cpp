/* 
965. Univalued Binary Tree

A binary tree is uni-valued if every node in the tree has the same value.
Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

 
Example 1:
Input: root = [1,1,1,1,1,null,1]
Output: true

Example 2:
Input: root = [2,2,2,5,2]
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 100].
0 <= Node.val < 100
Accepted
167,670
Submissions
242,753

*/


class Solution {
public:
    bool isUnivalTree(TreeNode* root, int val = -1) {
        if (!root) return true;
        if (val < 0) val = root->val;
        return root->val == val && isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
    }
  
   bool isUnivalTree(TreeNode* root) {
        return (!root->left || root->left->val == root->val && isUnivalTree(root->left)) &&
               (!root->right || root->right->val == root->val && isUnivalTree(root->right));
    }
};
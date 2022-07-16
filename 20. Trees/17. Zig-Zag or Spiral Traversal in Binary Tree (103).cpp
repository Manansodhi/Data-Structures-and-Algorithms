/*
103. Binary Tree Zigzag Level Order Traversal
Medium

6466

181

Add to List

Share
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
Accepted
755,185
Submissions
1,391,065
*/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
      if(root==NULL)
        return ans;
      
      queue<TreeNode*> q;
      q.push(root);
      bool l2r=1;
      //1 -> L to R
      //0-> R to L
      
      while(!q.empty()){
        
        int size = q.size();
        vector<int>row(size);
        for(int i=0;i<size;i++){
          TreeNode* node = q.front();
          q.pop();
          //find position to fill node's value
          int idx = (l2r) ? i : (size-1-i);
          row[idx] = node->val;
          
          if(node->left != NULL)
            q.push(node->left);
          if(node->right != NULL)
            q.push(node->right);
        }
        l2r = !l2r;
        ans.push_back(row);
      }
      return ans;
    }
};
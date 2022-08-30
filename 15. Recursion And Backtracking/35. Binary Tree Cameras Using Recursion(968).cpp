/*
968. Binary Tree Cameras
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 
Constraints:
The number of nodes in the tree is in the range [1, 1000].
Node.val == 0
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
  int dfs(TreeNode* tr, int& camera){
    if(tr == NULL)return 1; //base case
    int left=dfs(tr->left,camera), right=dfs(tr->right, camera);
    if(left==0 || right==0){
      // if at least 1 child is not monitored, we need to place a camera at current node 
      camera++;
      return 2;
    }
    else if(left==2 || right==2){
      // if at least 1 child has camera, the current node is monitored. Thus, we don't need to place a camera here
      return 1;
    }
    else{
      // if both children are monitored but have no camera, we don't need to place a camera here. We place the camera at its parent node at the higher level. 
      return 0;
    }
    return -1;//dummy return ;
  }
  
    int minCameraCover(TreeNode* root) {
        int camera=0;
      if(dfs(root,camera)==0)camera++;  // if root is not monitored, we place an additional camera here
      return camera;
    }
};
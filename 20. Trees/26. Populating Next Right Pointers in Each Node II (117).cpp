/*
117. Populating Next Right Pointers in Each Node II

Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, 
the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Example 1:
Input: root = [1,2,3,4,5,null,7]

        1
      /   \
     2      3
    /  \     \
  4     5     7

Output: [1,#,2,3,#,4,5,7,#]

        1---->NULL
       / \
      2-->3---->NULL
     / \   \
    4-->5-->7---->NULL
       

Explanation: Given the above binary tree (Figure A), your function should populate each next 
pointer to point to its next right node, just like in Figure B. The serialized output is in 
level order as connected by the next pointers, with '#' signifying the end of each level.

Example 2:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100
 

Follow-up:

You may only use constant extra space.
The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
*/


class Solution {
public:
    Node* connect(Node* root) {
      if(!root) return root;
      queue<Node*>q;
      q.push(root);
      
      while(!q.empty()){
        
        int size = q.size();
        Node* nextRightNode = NULL;
        
        for(int i=0;i<size;i++){
          Node* node = q.front();
          node->next = nextRightNode;
          nextRightNode = node;
          q.pop();
          if(node->right != NULL)
            q.push(node->right);

          if(node->left != NULL)
            q.push(node->left);
        }
      }
      return root;
    }
};
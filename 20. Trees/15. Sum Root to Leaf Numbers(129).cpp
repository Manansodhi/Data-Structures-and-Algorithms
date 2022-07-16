/*
129. Sum Root to Leaf Numbers
You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer 
will fit in a 32-bit integer.
A leaf node is a node with no children.

Example 1:
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 

Constraints:
The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.
*/

/*
Time and space complexity

Recursive : Time complexity: O(N) Auxiliary space: O(H) H-> height of tree
Iterative : Time Complexity: O(N) Space complexity: O(N) ->Stack

*/


class Solution {
public:
  int sum=0;
  void root2leaf(TreeNode* root, int value){
    if(root == NULL)
      return ;
    if(root->left == NULL && root->right==NULL)
    {
      sum += value*10 + root->val;
      return;
    }
     root2leaf(root->left,value*10 + root->val);
     root2leaf(root->right,value*10 + root->val);
  }
  
    int sumNumbers(TreeNode* root) {
      
      root2leaf(root,0);
      return sum;
    }
};

//Recursive
class Solution {
public:
    void findSum(TreeNode* root, int temp ,int &ans){
        if(root==NULL){
            return;
        }
        temp=temp*10+root->val;
        //If reached the last node
        if(root->left==NULL and root->right==NULL){
            ans+=temp;
        }
        findSum(root->left,temp,ans);
        findSum(root->right,temp,ans);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        //Output
        int ans=0;
        findSum(root,0,ans);
        return ans;
    }
};


//Iterative
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum=0;
        stack<pair<TreeNode*,int>> stck;
        stck.push({root,0});
        while(!stck.empty()){
            pair<TreeNode*,int> p=stck.top();
            stck.pop();
            TreeNode* cur_node=p.first;
            int cur_sum=p.second;
            if(cur_node!=NULL){
                cur_sum=cur_sum*10+cur_node->val;
                if(cur_node->left==NULL and cur_node->right==NULL){
                    totalSum+=cur_sum;
                }
                else{
                    if(cur_node->right){
                        stck.push({cur_node->right,cur_sum});
                    }
                    if(cur_node->left){
                        stck.push({cur_node->left,cur_sum});
                    }
                }
            }
        }
        return totalSum;
    }
};
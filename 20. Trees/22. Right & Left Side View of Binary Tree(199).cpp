/*
199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the 
values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []
 
Constraints:  
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100`
*/

//RECURSIVE SOLUTION
//Right Side view
class Solution {
public:
  
  void f(TreeNode* root, int level, vector<int> &res){
    if(root==NULL)
      return ;
    if(res.size() == level)
      res.push_back(root->val);
    f(root->right,level+1,res);
    f(root->left,level+1,res);
    
  }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
      f(root,0,res);
      return res;
    }
};


//Left side View

class Solution {
public:
  
  void f(TreeNode* root, int level, vector<int> &res){
    if(root==NULL)
      return ;
    if(res.size() == level)
      res.push_back(root->val);
    f(root->left,level+1,res); //ONLY CHANGE IS TO MAKE LEFT ->right and vice versa
    f(root->right,level+1,res);
    
  }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
      f(root,0,res);
      return res;
    }
};


//ITERATIVE SOLUTION
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
         //level
        map<int,int> mp;
               // node->val
        
        queue<pair<TreeNode*,int>> q;
        vector<int> ans;
        if(!root)
            return ans;
        
        q.push({root,0});
        
        while(!q.empty()){
            pair<TreeNode*,int> temp=q.front();
            TreeNode *frontNode=temp.first;
            int level=temp.second;
            q.pop();
            if(mp.find(level)==mp.end()){
                mp[level]=frontNode->val;
            }
            
            if(frontNode->right){
                q.push({frontNode->right,level+1});
            }
            
            if(frontNode->left){
                q.push({frontNode->left,level+1});
            }
        }
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
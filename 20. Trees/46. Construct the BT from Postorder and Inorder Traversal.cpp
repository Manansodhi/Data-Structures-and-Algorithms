class Solution {
public:
        
    
  TreeNode* buildTreePostIn(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> &inMap){
    if(postStart > postEnd || inStart > inEnd){
      return NULL;
    }
    
    TreeNode*root = new TreeNode(postorder[postEnd]);
    int inRoot = inorder[postorder[postEnd]];
    int numsLeft = inRoot - inStart;
    
    root->left = buildTreePostIn(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, inMap);
    root->right = buildTreePostIn(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1,inEnd,inMap);
    return root;
  }
  
  
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if (inorder.size() != postorder.size())
            return NULL;
      map<int,int>inMap;
      for(int i=0;i<inorder.size();i++)
        inMap[inorder[i]] = i;
      
      return buildTreePostIn(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);
     
    }
};

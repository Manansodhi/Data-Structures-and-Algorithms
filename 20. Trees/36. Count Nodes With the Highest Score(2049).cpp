/*
2049. Count Nodes With the Highest Score

There is a binary tree rooted at 0 consisting of n nodes. The nodes are labeled from 0 to n - 1. 
You are given a 0-indexed integer array parents representing the tree, where parents[i] is the 
parent of node i. Since node 0 is the root, parents[0] == -1.

Each node has a score. To find the score of a node, consider if the node and the edges connected 
to it were removed. The tree would become one or more non-empty subtrees. The size of a subtree 
is the number of the nodes in it. The score of the node is the product of the sizes of all those 
subtrees.

Return the number of nodes that have the highest score.

 
Example 1:

example-1
Input: parents = [-1,2,0,2,0]
Output: 3

Explanation:
- The score of node 0 is: 3 * 1 = 3
- The score of node 1 is: 4 = 4
- The score of node 2 is: 1 * 1 * 2 = 2
- The score of node 3 is: 4 = 4
- The score of node 4 is: 4 = 4
The highest score is 4, and three nodes (node 1, node 3, and node 4) have the highest score.

Example 2:
example-2
Input: parents = [-1,2,0]
Output: 2

Explanation:
- The score of node 0 is: 2 = 2
- The score of node 1 is: 2 = 2
- The score of node 2 is: 1 * 1 = 1
The highest score is 2, and two nodes (node 0 and node 1) have the highest score.
 
Constraints:
n == parents.length
2 <= n <= 105
parents[0] == -1
0 <= parents[i] <= n - 1 for i != 0
parents represents a valid binary tree.
*/

class Solution{
	class TreeNode{
		private:
			TreeNode * left;
			TreeNode * right;
			long score=0l;
			int nodeCount=0;
	}
	int countNodes(TreeNode root){
		if(root==NULL)
			return 0;
		root->nodeCount = countNodes(root->left) + countNodes(root->right)+1; //postOrder
		return root->nodeCount;
	}

public:
	int countHighestScoreNodes(vector<int>parents){
		int max=0,n=parents.size(),ans=0;
		TreeNode[] tree = new TreeNode [n];

		for(int i = 0;i<parents.length;i++){
			tree[i] = new TeeNode();
		}

		for(int i=1;i<parents.length;i++){
			int parentId = parent[i];
			if(trr[parentId]->left == NULL)
				tree[parentId]->left = tree[i];
			else
				tree[parentId]->right = tree[i];
		}

		countNodes(tree[0]);

		for(int i=0;i<psrents.length; i++){
			long product = 1;
			int leftcnt = tree[i]->left==NULL ? 0 : tree[i].left->nodeCount;
			int rightcnt = tree[i]->right==NULL ? 0 : tree[i]->right.nodeCount; 
			int parentcnt = n-1-leftcnt-rightcnt;

			if(leftcnt > 0)
			product *= leftcnt;
			if(rightcnt > 0)
			product *= rightcnt;
			if(parentcnt>0)
			product *= parentcnt;

			tree[i]->score = product;
			maxi = max(maxi,product); 
		}

		//count nodes
		for(int i=0;i<parents.length();i++){
			if(tree[i].score == max)
				ans++;
		}
		return ans;
	}
};


class Solution {
     int helper(int src,vector<vector<int>>& g,vector<int>& size){
         int ans = 1;
         for(auto child:g[src]){
             ans += helper(child,g,size);
         }
         return size[src] = ans; 
     }
    
    
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> size(n,0);  // size[i] indicates size of subtree(rooted at i node) + 1
        vector<vector<int>> g(n); // storing left and right child of a node
        for(int i=1;i<n;i++){
            g[parents[i]].push_back(i);
        }
        helper(0,g,size);  // calculating size of each subtree
        long long cnt = 0, maxi = 0;
        for(int i=0;i<n;i++){
            long long pro = 1; 
            pro = max(pro,(long long)n - size[i]); // calculating leftover nodes excluding child nodes 
            for(auto node:g[i]){
                pro = pro * size[node]; // multiplying with size of subtree
            }
            if(pro > maxi){
                maxi = pro;
                cnt = 1;
            }
            else if(pro == maxi){
                cnt++;
            }
        }
        return cnt;
    }
};


// The value of a node is the product of:

// number of nodes in the left subtree,
// number of nodes in the right subtree,
// number of all other nodes, excluding the current one (n - left - right - 1)
// We can just use DFS to count child nodes for (1) and (2), and we can then compute (3) as we know the total nubers of nodes.

C++

int dfs(vector<vector<int>> &al, vector<long long> &s, int i) {
    long long prod = 1, sum = 1;
    for (int j : al[i]) {
        int cnt = dfs(al, s, j);
        prod *= cnt;
        sum += cnt;
    }
    s[i] = prod * (max(1ll, (long long)al.size() - sum));
    return i != 0 ? sum : count(begin(s), end(s), *max_element(begin(s), end(s)));
}
int countHighestScoreNodes(vector<int>& p) {
    vector<vector<int>> al(p.size());
    vector<long long> s(p.size());
    for (int i = 1; i < p.size(); ++i)
        al[p[i]].push_back(i);
    return dfs(al, s, 0);
}


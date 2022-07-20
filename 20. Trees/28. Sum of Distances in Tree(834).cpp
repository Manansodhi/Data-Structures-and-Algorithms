/*
834. Sum of Distances in Tree

There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there 
is an edge between nodes ai and bi in the tree.
Return an array answer of length n where answer[i] is the sum of the distances between the ith
node in the tree and all other nodes.

 
Example 1:
Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]

Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.

Example 2:
Input: n = 1, edges = []
Output: [0]

Example 3:
Input: n = 2, edges = [[1,0]]
Output: [1,1]
 
Constraints:
1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
The given input represents a valid tree.


Explanation
Let's first solve a simpler version of this problem.
Suppose we need to find the sum of distances for only root node.


Consider the tree above, with 0 as the root node.
The result for subtree with 2 as root will be 2 (we can easily count it) and for 
subtree 1 is 1.

This is the recurrence relation we can use to calculate the sum of distances for root.

res[0] = res[2] + number of nodes in subtree with root 2
		+ res[1] + number of nodes in subtree with root 1

res[0] = 2 + 3 + 1 + 2 = 8
We are adding the number of nodes of subtree because every node in subtree will be 1 unit more 
far from the original root.

I need two arrays count and res. Count will store the number of nodes in each subtree and res
will the store the answer as discussed above. Below is the code.

	// intially count array was initialized to 0.
	// count[parent] is the sum of count of its child + 1
	// v is the Adjacency List
	void dfs(int i, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            dfs(u, i);
            count[i] += count[u];
            res[i] += res[u] + count[u];
        }
        count[i] += 1;
    }
This ends the first part of our problem.

The Original problem
We can run the dfs function above for every node and get the solution. This will result in 
O(N * N) time complexity. But we can do this in O(N) time using a technique popularly known as re-rooting techinque.

The idea is to derive the solution of every node by shifting the root.

Suppose we shift the root from root 0 to 1, what changes can we observe.
count[1] nodes got 1 unit closer to new root and n - count[1] nodes got 1 unit away from the
new root.So,
res[1] = res[0] - count[1] + n - count[1]
i.e
res[new_root] = res[root] - count[new_root] + n - count[new_root]

The way we are running dfs the new_root will be child and root will be parent.
Here, is the code for this part.

    void dfs2(int i, int n, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            res[u] = res[i] - count[u] + n - count[u];
            dfs2(u, n, i);
        }
    }
Complete Code
*/

class Solution {
public:
    vector<vector<int>> v;
    vector<int> counter, res;
        
    void dfs(int i, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            dfs(u, i);
            counter[i] += counter[u];
            res[i] += res[u] + counter[u];
        }
        counter[i] += 1;
    }

    void dfs2(int i, int n, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            res[u] = res[i] - counter[u] + n - counter[u];
            dfs2(u, n, i);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        v.resize(n);
        for(int i = 0; i < n - 1; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        res.resize(n);
        counter.resize(n);
        dfs(0);
        dfs2(0, n);
        return res;
    }
};

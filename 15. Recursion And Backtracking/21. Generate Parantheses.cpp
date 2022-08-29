/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed 
parentheses.


Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
 
Constraints:
1 <= n <= 8
*/
class Solution {
public:
    
    void helper(vector<string> &v, int n, int oc, int cc, string s){
        if(oc==n&&cc==n){
            v.push_back(s);
            return ;
        }
        if(oc<n)
            helper(v,n,oc+1,cc,s+"(");
        if(cc<oc)
            helper(v,n,oc,cc+1,s+")");
    }
    
    vector<string> generateParenthesis(int n) {
        int oc=0,cc=0;
        vector<string>v;
        helper(v,n,oc,cc,"");
        return v;
    }
};

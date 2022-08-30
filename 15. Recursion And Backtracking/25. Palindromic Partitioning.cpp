/*
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.


Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]
 
Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.

*/

class Solution {
public:
    
    bool isPalindromic(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
    void func(int idx, string s, vector<string> &path, vector<vector<string>> &ans){
        if(idx==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalindromic(s,idx,i)){
                path.push_back(s.substr(idx, i-idx+1));
                func(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        func(0,s,path,ans);
        return ans;
    }
};
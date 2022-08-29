/*
784. Letter Case Permutation

Given a string s, you can transform every letter individually to be lowercase or uppercase to 
create another string.Return a list of all possible strings we could create. Return the output 
in any order.

Example 1:
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: s = "3z4"
Output: ["3z4","3Z4"]
 
Constraints:
1 <= s.length <= 12
s consists of lowercase English letters, uppercase English letters, and digits.
*/



class Solution {
public:
    
    void f(string &s, string curr, int idx, vector<string> &ans){
        //base
        if(curr.size()==s.size()){
            ans.push_back(curr);
            return;
        }
        if(s[idx]>='0' && s[idx]<='9')
            f(s,curr+s[idx],idx+1,ans);
        else{
            f(s,curr+(char)(toupper(s[idx])),idx+1,ans);
            f(s,curr+(char)(tolower(s[idx])),idx+1,ans);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        f(s,"",0,ans);
        return ans;
    }
};
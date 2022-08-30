/*
1249. Minimum Remove to Make Valid Parentheses

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so 
that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 
Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
 
Constraints:
1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.
Accepted
459,957
Submissions
701,008
Seen this question in a real interview before?
Yes
No

*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0;
        string ans="";
        for(char c:s){
            if(c=='('){
                open++;
                ans+=c;
            }
            else if(c==')'){
                if(open>0){
                    open--;
                    ans+=c;
                }
                else
                    continue;
            }
            else
                ans+=c;
        }
        
        int n=ans.size();
        string newAns="";
        if(open>0){
            for(int i=n-1;i>=0;i--){
                if(ans[i]=='(' && open>0)
                    open--;
                else
                    newAns+=ans[i];
            }
            reverse(newAns.begin(),newAns.end());
        }
        else
            newAns=ans;
        return newAns;
    }
};
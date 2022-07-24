
/*
392. Is Subsequence
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by 
deleting some (can be none) of the characters without disturbing the relative positions
of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:
0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "")
          return true;
      if(t=="")
        return false;
      if(s.size()==1 && t.size()==1)
        return s[0]==t[0];
      
      int i=0,j=0;
      while(i<t.length() && j<s.size()){
        if(s[j]==t[i]){
          i++;
          j++;
        }
        else{
            i++;
       }
      }
      if(j==s.length()){
        return true;
      }
      else{
        return false;
      }
      
    }
};
      
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> mp; 
        for(int i=0; i<t.length();i++) mp[t[i]].push_back(i);
        
        int prev = -1;
        for(auto c : s){
            auto it = mp.find(c);
            if(it == mp.end()) return false;
            auto vec = it->second;
            int pos = upper_bound(vec.begin(), vec.end(), prev) - vec.begin(); 
            if(pos == vec.size()) return false;
            prev = vec[pos];
        }
        return true;
    }
};
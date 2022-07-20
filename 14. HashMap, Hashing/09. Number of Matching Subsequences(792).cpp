/*
792. Number of Matching Subsequences
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
 

Example 1:
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 
Constraints:
1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/


class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
      vector<vector<int>> charIdx(26);
      for(int i=0;i<s.size();i++){
        charIdx[s[i]-'a'].push_back(i);
      }
      
      int count = 0;
      for(int i=0;i<words.size();i++){
        bool isSubsequence = true;
        int lastcharIdx = -1;
        for(char w:words[i]){
          auto it = upper_bound(charIdx[w-'a'].begin(), charIdx[w-'a'].end(), lastcharIdx);
          if(it==charIdx[w-'a'].end()){
            isSubsequence=false;
            break;
          }
          else{
            lastcharIdx = *it;
          }
        }
        if(isSubsequence)
          count++;
      }
      return count;
    }
};



class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        map<string, int> m;
        for(string str: words) m[str]++;
        int ans = 0;
        for(auto[str, k]: m){
            int i = 0, j = 0;
            while(i<s.length() && j<str.length()){
                if(s[i]==str[j]){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
            if(j==str.length()){
                ans+=m[str];
            }
            
        }
        
      return ans;
    }
};
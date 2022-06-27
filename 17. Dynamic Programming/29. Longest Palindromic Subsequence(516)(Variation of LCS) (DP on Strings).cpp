/*
516. Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no 
elements without changing the order of the remaining elements.


Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 
Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters.

Sample Input 1:
bbabcbcab
bbbab

Sample Output 1:
7
4

Explanation Of Sample Input 1:
For the first test case, the longest palindromic subsequence is “babcbab”, which has a length of 7. 
“bbbbb” and “bbcbb” are also palindromic subsequences of the given string, but not the longest one.
For the second test case, the longest palindromic subsequence is “bbbb”, which has a length of 4.

Sample Input 2:
cbbd
bebeeed
abcd

Sample Output 2:
2
4
1

*/


class Solution {
public:
  int lcs(string s1, string s2) {
      int n = s1.size();
      int m = s2.size();
      vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 
        
      //base case
        for(int idx1=0;idx1<=n;idx1++)
            dp[idx1][0]=0;
        for(int idx2=0;idx2<=m;idx2++)
            dp[0][idx2]=0;
             
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(s1[idx1-1] == s2[idx2-1]) 
                     dp[idx1][idx2] = (1+dp[idx1-1][idx2-1]);
                else 
                    dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
            }
        }
      return dp[n][m];
    }


	int longestPalindromeSubseq(string s)
	{
	    string t = s;
	    reverse(t.begin(), t.end());
	    return lcs(s,t);
	}
};
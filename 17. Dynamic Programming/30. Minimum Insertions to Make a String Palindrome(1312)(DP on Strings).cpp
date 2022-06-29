/*
Minimum insertions to make a string palindrome
A palindrome string is one that reads the same backward as well as forward. Given a string 'STR', 
you need to tell the minimum number of characters needed to insert into it to make it a palindromic 
string.

For example:
String 'STR' = “abcaa” can be converted into a palindrome by inserting 2 characters. So the final 
string becomes “aabcbaa”.
Constraints:
1 <= T <= 100   
1 <= |STR| <= 10 ^ 2

Where |STR| represents the length of the string 'STR'.
Time Limit: 1 sec.

Sample Input 1:
2
abcaa
edge

Sample Output 1:
2
1

Explanation For Input 1:
For test case 1: Refer to example explain above.
For test case 2: you can make “egdge” or “edgde” in one operation.

Sample Input 2:
2
codingninjas
helper

Sample Output 2:
7
3
*/

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


int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s,t);
}


int minInsertion(string &str)
{
    return str.size() - longestPalindromeSubsequence(str);
}
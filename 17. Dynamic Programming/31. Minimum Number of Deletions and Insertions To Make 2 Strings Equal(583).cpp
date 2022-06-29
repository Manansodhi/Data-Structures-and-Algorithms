/*
Minimum Number of Deletions and Insertions

You are given 2 non-empty strings “str” and “ptr” consisting of lowercase English alphabets only.
Your task is to convert string “str” into string “ptr”. In one operation you can do either of the 
following on “str”:

Remove a character from any position in “str”.
Add a character to any position in “str”.
You have to find the minimum number of operations required to convert string “str” into “ptr”.

For Example:
If str = “abcd”, ptr = “anc”
In one operation remove str[3], after this operation str becomes “abc”.    
In the second operation remove str[1], after this operation str becomes “ac”.
In the third operation add ‘n’ in str[1], after this operation str becomes “anc”.
Hence, the output will be 3.

Constraints:
1 <= T <= 10
1 <= str.length, ptr.length <= 100
Time limit: 1 sec

Sample Input 1 :
2
abcd anc
aa aaa

Sample Output 1 :
3
1
Explanation For Sample Output 1:
For the first test case,
str = “abcd”, ptr = “anc”
In one operation remove str[3], after this operation str becomes “abc”.
In the second operation remove str[1], after this operation str becomes “ac”.
In the third operation add ‘n’ in str[1], after this operation str becomes “anc”.
Hence, the output will be 3.

For the second test case,
str = “aaa”, ptr = “aa”
In one operation remove str[2], after this operation str becomes “aa”.
Hence, the output will be 1.

Sample Input 2 :
2
cue dgo
edl xcqja

Sample Output 2 :
6
8
*/


  int longestCommonSubsequence(string s1, string s2) {
      int n = s1.size();
      int m = s2.size();
      vector<int>prev(m+1,0), curr(m+1,0); 
        
      //base case
        for(int idx1=0;idx1<=n;idx1++)
            prev[0]=0;
       
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(s1[idx1-1] == s2[idx2-1]) 
                     curr[idx2] = (1+prev[idx2-1]);
                else 
                    curr[idx2] = max(prev[idx2], curr[idx2-1]);
            }
            prev=curr;
        }
        
      return prev[m];
  }
    
    int canYouMake(string &str1, string &str2) {
        int Deletion = str1.length()-longestCommonSubsequence(str1, str2);
      int Inserion = str2.length()-longestCommonSubsequence(str1, str2);
      return Deletion+Inserion;
    }


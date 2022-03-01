/*
Love for Characters

Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times 
characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.

Input:
First line contains an integer denoting length of the string.
Next line contains the string.

Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’

Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.

Sample Input:
6
aabsas

Sample output:

3 2 0
*/
#include"bits/stdc++.h"
using namespace std;


 int main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
     int n;
     string s;
     cin >> n >> s;

     map<char, int> m;
      for (int i = 0; i < s.size(); i++){
        m[s[i]]++;
      }

      cout << m['a'] <<" " << m['s'] <<" " << m['p'] << " " << endl;
      
     return 0;
 }
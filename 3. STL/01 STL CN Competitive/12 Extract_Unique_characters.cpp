/*
Extract Unique characters

Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. 
The respective order of characters should remain same, as in the input string.

Input format:
The first and only line of input contains a string, that denotes the value of S.
Output format :
The first and only line of output contains the updated string, as described in the task.

Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec

Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif    
    char str[1000000];
    cin >> str;
    char out[1000000];
    unordered_map<char, int>m;
    int j = 0;
    for (int i = 0; i < strlen(str); i++){
        m[str[i]]++;
        if (m[str[i]] == 1){
            out[j] = str[i];
            j++;
        }

    }
    out[j] = '\0';
    cout <<out << endl;
    return 0;
}
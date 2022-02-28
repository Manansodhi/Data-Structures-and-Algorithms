#include<bits/stdc++.h>
using namespace std;


/*
Given a string str consisting of lowercase English letters, the task is to find the longest palindromic string T which satisfies
the following condition:

1. T = p + m + s where p and s are the prefix and the suffix of the given string str respectively and the string m is either the
   prefix or suffix of the string str after removing both p and s from it.
2. The string formed by the concatenation of p and s is a palindrome itself.
3. Either of the strings p and s can be an empty string.

Examples:
Input: str = “abcdfdcecba”
Output: abcdfdcba

Explanation:
Here, p = “abc”
s = “cba”
m = “dfd”
p + s = “abccba” which is a palindrome and m = “dfd” is the prefix after removing the prefix and suffix from the string str.
Therefore, T = “abcdfdcba”.

Input: str = “geeksforgeeks”
Output: g
Explanation:
Here, p = “”
s = “”
m = “g”
p + s = “” which is a palindrome and m = “g” is the prefix after removing the prefix and suffix from the string str. Therefore,
T = “g”.



Approach: The idea for this problem is to divide the answer into three parts, such that there will be a part of suffix and prefix
of the given string which forms palindrome together which will form the beginning and the ending of the answer string. Now, after
removing these prefix and suffix from the given string, we can find the maximum lengthed suffix or prefix string (which we may call
midPalindrome) which is palindromic.
Therefore, the answer string will be given by:

answer = prefix + midPalindrome + suffix

The following steps can be followed to compute the answer to the problem:
1. Find the length up to which the suffix and prefix of str form a palindrome together.
2. Remove the suffix and prefix substrings which already forms a palindrome from str and store them in separate strings.
3. Check all prefix and suffix substrings in the remaining string str and find the longest of such strings.
4. Finally, combining all the three parts of the answer and return it.
*/

// To check string is palindrome or not
bool isPalindrome(string r) {
	string p = r;
	reverse(p.begin(), p.end());
	return (p == r);
}

//function to find longest palindrome in a string formed by concatenating its prefix and suffix

string PrefixSuffixPalindrome(string str) {
	//find the length upto which suffix and prefix forms a palindrome together
	int n = str.size(), len = 0;
	for (int i = 0; i < n / 2; i++) {
		if (str[i] != str[n - i - 1]) {
			len = i;
			break
		}
	}

	//check whether the string has prefix and suffix substrings are palindrome or not
	string prefix = "", suffix = "", midPal = "";


	//Removing prefix and suffix substrings which already forms a palindrome and storing them in separte strings
	prefix = str.substr(0, len);
	suffix = str.substr(n - len);
	str = str.substr(len, n - 2 * len); //this is string of length after removing 2 string of length=len  from start and end


	//check all prefix substrings in the remaining string str
	for (int i = 1; i <= str.size(); i++) {
		string y = str.substr(0, i);

		//if prefix substring is palindrome
		if (isPalindrome(y)) {
			//if prefix substring is palindrome then check if it is of maximum length so far
			if (midPal.size() < y.size()) {
				midPal = y;
			}
		}
	}

	//check all suffix substrings in the remaining string str
	for (int i = 1; i <= str.size(); i++) {
		string y = str.substr(str.size() - i);

		if (isPalindrome(y)) {
			if (midPal.size() < y.size()) {
				midPal = y;
			}
		}
	}

	string answer = prefix + midPal + suffix;

	return answer;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s ;
	cin >> s;
	cout << PrefixSuffixPalindrome(s) << endl;


	return 0;
}
/*
Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.

*/


#include<bits/stdc++.h>
using namespace std;

/*
Naive Approch
Time Complexity: O( N^2 )
Space Complexity: O(N) where N is the size of HashSet taken for storing the elements

This approach consists of taking the two loops one for traversing the string and another loop – nested loop for finding different
substrings and after that, we will check for all substrings one by one and check for each and every element if the element is not
found then we will store that element in HashSet otherwise we will break from the loop and count it.

*/

int LongestSubstringWithoutRepeatingCharacters(string s) {
	int len = INT_MIN;
	// outer loop for traversing the string
	for (int i = 0; i < s.length(); i++) {
		unordered_set<int>set;
		// nested loop for getting different string starting with s[i]
		for (int j = i; j < s.length(); j++) {
			// if element if found so mark it as ans and break from the loop
			if (set.find(s[j]) != set.end()) {
				len = max(len, j - i);
				break;
			}
			set.inser(s[j]);
		}
	}
	return len;
}


/*
Optimised  Approach 1
Time Complexity: O( 2*N ) (sometimes left and right both have to travel complete array)
Space Complexity: O(N) where N is the size of HashSet taken for storing the elements

We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point of substring while ‘right’
will maintain the endpoint of the substring.’ right’ pointer will move forward and check for the duplicate occurrence of the
current element if found then ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.

*/

int LongestSubstringWithoutRepeatingCharacters(string s) {
	int len = INT_MIN;
	unordered_set<int> set;
	int left = 0;
	for (int right = 0; right < s.length(); right++) {
		if (set.find(s[right]) != set.end()) {
			while (left < right && set.find(s[right]) != set.end()) {
				set.erase(s[left]);
				left++;;
			}
		}
		set.insert(s[right]);
		len = max(len, right - left + 1);
	}
	return len;
}


/*
Optimised  Approach 2
Time Complexity: O( N )
Space Complexity: O(N) where N represents the size of HashSet where we are storing our elements

Problem we were facing in previous approch was when we have to remove duplicate element we have to traverse left the N times in 
worse case to remove duplicate and reach at right. Now we will straight away jump left to right. we solve this by storing the 
index of last character found and when this same character appears again then we will jump straight to index of that character 
stored in map

*/

int LongestSubstringWithoutRepeatingCharacters(string s) {
	vector<int>map(256, -1);
	int left = 0, right = 0, len = 0, n = s.size();
	while (right < n) {
		if (map[s[right]] != -1)
			left = max(map[s[right]] + 1, left);

		map[s[right]] = right;
		len = max(len, right - left + 1);
		right++;
	}
	return len;
}

//Easy To Understand Code
int LongestSubstringWithoutRepeatingCharacters(string s){
	if(s.size()==0){
		return 0;
	}
	int n = s.size();
	int i(0),j(0);
	 vector<int> cnt (256,0);
	 cnt[s[0]]++;
	 int len = 1;
	 while(j!=n-1){
	 	if(cnt[s[j+1]] == 0){
	 		j++;
	 		cnt[s[j]]++;
	 		len = max(len,j-i+1);
	 	}
	 	else{
	 		cnt[s[i]]--;
	 		i++;	
	 	}
	 }
	 return len;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	string s;
	cin >> s;
	cout << LongestSubstringWithoutRepeatingCharacters(string s) << endl;
	return 0;
}
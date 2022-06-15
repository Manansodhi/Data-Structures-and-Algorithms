/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) {
			return 0;
		}
		int n = s.size();
		int left(0), right(0);
		vector<int> mpp (256, -1);
		int len = 0;
		while (right < n) {
			if (mpp[s[right]] != -1) //eska matlab h ki repeating char h substring m eska matlab h hane direct jump karana
				left = max(mpp[s[right]] + 1, left);
			mpp[s[right]] = right;
			len = max(right - left + 1, len);
			right++;
		}
		return len;
	}
};

class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		unordered_map<char, int> u;
		for (char ch : s)
			u[ch] = 0;
		int left = 0, right = 0;
		int best = 0;
		while (right < s.length())
		{
			if (u[s[right]] == 0)
			{
				u[s[right]]++;
				right++;

			}
			else
			{
				u[s[left]]--;
				left++;

			}
			best = max(best, right - left);

		}
		return best;

	}
};
/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s
such that every character in t (including duplicates) is included in the window. If there is no such
substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Algorithm
1 We start with two pointers,left and right initially pointing to the first element of the string S.

2 We use the right pointer to expand the window until we get a desirable window i.e. a window that
contains all of the characters of T.

3 Once we have a window with all the characters, we can move the left pointer ahead one by one. If the
window is still a desirable one we keep on updating the minimum window size.

4 If the window is not desirable any more, we repeat step2 onwards


Complexity Analysis
Time Complexity: O(|S| + |T|) where |S| and |T| represent the lengths of strings S and T.
In the worst case we might end up visiting every element of string SS twice, once by left pointer and
once by right pointer. |T| represents the length of string T.

Space Complexity: O(|S| + |T|). |S| when the window size is equal to the entire string S. |T| when T
has all unique characters.


Approach 2: Optimized Sliding Window

Intuition
A small improvement to the above approach can reduce the time complexity of the algorithm to
O(2*|filtered_S| + |S| + |T|), where filtered_S is the string formed from S by removing all the
elements not present in TT.

This complexity reduction is evident when |filtered_S| <<< |S|.
This kind of scenario might happen when length of string T is way too small than the length of string S
and string S consists of numerous characters which are not present in T.

Algorithm
We create a list called filtered_S which has all the characters from string S along with their indices
 in S, but these characters should be present in T.

  S = "ABCDDDDDDEEAFFBC" T = "ABC"
  filtered_S = [(0, 'A'), (1, 'B'), (2, 'C'), (11, 'A'), (14, 'B'), (15, 'C')]
  Here (0, 'A') means in string S character A is at index 0.
We can now follow our sliding window approach on the smaller string filtered_S
*/

class Solution {
public:
     string minWindow(string s, string t) {
          vector<int> hist(128, 0);
          for (char c : t) //calculating Frequency of character in T
               hist[c]++;

          int remaining = t.length();
          int left = 0, right = 0, minStart = 0, minLen = numeric_limits<int>::max();

          /*The std::numeric_limits<T>::max() function is used to get the maximum finite value representable by the numeric type T
          int main()
          {
          cout << "bool: "
             << numeric_limits<bool>::max()
             << '\n';

          // It returns 127 in ASCII value
          // to print in integer that can
          // be typecast it to int()
          cout << "char: "
             << int(numeric_limits<char>::max())
             << '\n';

          cout << "unsigned char: "
             << int(numeric_limits<unsigned char>::max())
             << '\n';

          cout << "short: "
             << numeric_limits<short>::max()
             << '\n';

          cout << "int: " << numeric_limits<int>::max()
             << '\n';

          cout << "unsigned int: "
             << numeric_limits<unsigned int>::max()
             << '\n';

          cout << "long long: "
             << numeric_limits<long long>::max()
             << '\n';

          cout << "float: "
             << numeric_limits<float>::max()
             << '\n';

          cout << "double: "
             << numeric_limits<double>::max()
             << '\n';

          cout << "size_t: "
             << numeric_limits<size_t>::max()
             << '\n';
          }
          Output:
          bool: 1
          char: 127
          unsigned char: 255
          short: 32767
          int: 2147483647
          unsigned int: 4294967295
          long long: 9223372036854775807
          float: 3.40282e+38
          double: 1.79769e+308
          size_t: 18446744073709551615
          */

          while (right < s.length()) {
               /* Jab window expand kar rahe toh check kar rahe h uskifrequency >=0 h na or usko reduce bhi kar rahe by -1 or sath m jo hame required number of characters for substring ko bhi reduce kar rahe by -1*/
               if (--hist[s[right++]] >= 0)
                    remaining--;

               //jab hmae required length of window bna le (remaining==0)
               while (remaining == 0) {
                    if (right - left < minLen) {
                         //agar ko choti substring mil rahi phele wale se toh usko update kardo choti wali substring se
                         minLen = right - left;
                         minStart = left;
                    }

                    /*//Ab jab hum contraction kar rahe h left se toh frequency us character ki increase bhi kar rahe h sath sath or reamining++ ki hmare window size m size remaining h pura nahi hua*/

                    if (++hist[s[left++] > 0])
                         remaining++;
               }
          }
          return minLen < numeric_limits<int>::max() ? s.substr(minStart, minLen) : "";
     }
};
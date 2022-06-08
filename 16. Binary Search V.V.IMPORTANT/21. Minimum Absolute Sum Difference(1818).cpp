/*
1818. Minimum Absolute Sum Difference

You are given two positive integer arrays nums1 and nums2, both of length n.
The absolute sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).
You can replace at most one element of nums1 with any other element in nums1 to minimize the absolute sum difference.
Return the minimum absolute sum difference after replacing at most one element in the array nums1. Since the answer may be large, return it modulo 109 + 7.

|x| is defined as:
x if x >= 0, or
-x if x < 0.

Example 1:
Input: nums1 = [1,7,5], nums2 = [2,3,5]
Output: 3
Explanation: There are two possible optimal solutions:
- Replace the second element with the first: [1,7,5] => [1,1,5], or
- Replace the second element with the third: [1,7,5] => [1,5,5].
Both will yield an absolute sum difference of |1-2| + (|1-3| or |5-3|) + |5-5| = 3.

Example 2:
Input: nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
Output: 0
Explanation: nums1 is equal to nums2 so no replacement is needed. This will result in an
absolute sum difference of 0.

Example 3:
Input: nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
Output: 20
Explanation: Replace the first element with the second: [1,10,4,4,2,7] => [10,10,4,4,2,7].
This yields an absolute sum difference of |10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20

Constraints:
n == nums1.length
n == nums2.length
1 <= n <= 105
1 <= nums1[i], nums2[i] <= 105
*/

int minabsoluteSumDiff(vector<int>& n1, vector<int>& n2) {
	// originalDiffSum - will accumulate sum of difference without replacement
	// maxDecrement - will store max decrement possible after replacement at any index of n1
	long maxDecrement = 0, originalDiffSum = 0,;
	set<int> s(n1.begin(), n1.end());
	for (int i = 0; i < n1.size(); i++) {
		long currDiff  = abs(n1[i] - n2[i]); // original difference for current index without replacement
		originalDiffSum += currDiff ;
		// find closest element to n2[i] so that after replacement, diff is minimized
		// lower_bound will return smallest number greater than or equal to n2[i].
		// So we also need to check previous value of lower_bound in 's' which may further minimize the absolute difference.

		auto it = s.lower_bound(n2[i]);
		if (it != s.begin())
			maxDecrement = max(maxDecrement, currDiff - abs(*prev(it) - n2[i]));
		if (it != s.end())
			maxDecrement = max(maxDecrement, currDiff - abs(*it - n2[i]));
	}
	// finally apply the maximum decrement that can be done after replacement
	return (originalDiffSum - maxDecrement) % 1000000007;

}
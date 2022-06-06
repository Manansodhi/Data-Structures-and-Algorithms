/*2148. Count Elements With Strictly Smaller and Greater Elements

Given an integer array nums, return the number of elements that have both a strictly smaller and a strictly greater element appear in nums.


Example 1:
Input: nums = [11,7,2,15]
Output: 2
Explanation: The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.
Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.
In total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.

Example 2:
Input: nums = [-3,3,3,90]
Output: 2
Explanation: The element 3 has the element -3 strictly smaller than it and the element 90 strictly greater than it.
Since there are two elements with the value 3, in total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.


Constraints:
1 <= nums.length <= 100
-105 <= nums[i] <= 105*/


/*
1. Min Max using Multiple passes
Algorithm
Find the max and min element of array, store in M and m variables
Compare each element with Min and Max and count while iterating through array in O(N) time
Return the count as result.
Space Complexity: O(1)
Time Complexity: O(N)

Intuition:
If you find the max and min of complete array, each element compared will satisfy the condition that needs to checked.

Array = [11, 7, 2, 15]
Max = 15
Min = 2

For iteration i = 0: check if (11>2 && 11 <15)
increase count

And so on..

Finally return count
*/

class solution {
public:
	int countElements(vector<int>&nums) {
		int M = *max_element(nums.begin(), nums.end());
		int n = *min_element(nums.begin(), nums.end());

		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > m && nums[i] < M)
				res++;
		}
		return res;
	}
};


/*
2. Min Max using Single passes [Map]
Algorithm
Find the max and min element of array, store in m and l variables
In the same loop use an unordered map to store the frequenecy of each element
Return the value of nums.size()-map[m]-map[l] as result.
Space Complexity: O(N)
Time Complexity: O(N) Single Pass
*/

class solution {
public:
	int countElements(vector<int>&nums) {
		unordered_map<int, int>map;
		int m = INT_MIN;
		int l = INT_MAX;
		for (int x : nums) {
			map[x]++;
			m = max(m, x);
			l = min(l, x);
		}
		if (m == l) {
			return 0;
		}
		return nums.size() - map[m] - map[l];
	}
};


/*Next Permutation
Problem Description:
Given an array Arr[], Treat each element of the array as the digit and whole array as the number. Implement the
next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

Note: The replacement must be in-place, do not allocate extra memory.
Input Format: The First Line contains the Number of test cases T.
Next Line contains an Integer N,  number of digits of the number.
Next Line contains N-space separated integers which are elements of the array 'Arr'.

Constraints: 1 <= T <= 100
1 <= N <= 1000
0 <= Ai <= 9

Sample Input:
2
3
1 2 3
3
3 2 1

Output Format: Print the Next Permutation for each number separated by a new Line.
Sample Output:
1 3 2
1 2 3


*/

#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>&nums) {
	int n = nums.size();
	if (n == 1) {
		return;
	}
	int index1;
	for (int i = n - 2; i >= 0; i--) {
		if (nums[i] < nums[i + 1]) {
			index1 = i;
			break;
		}
		int index2 = 0;
		if (index1 < 0) {
			reverse(nums.begin(), nums.end());
		}
		else {
			for (int i = n - 1; i >= 0; i--) {
				if (nums[i] > nums[index1]) {
					index2 = i;
					break;
				}
			}
		}
		swap(nums[index1], nums[index2]);
		reverse(nums.begin() + index1 + 1, nums.end());
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>v(n);
	int number;
	for (int i = 0; i < n; i++) {
		cin >> number;
		v.push_back(number);
	}
	nextPermutation(v);
	return 0;
}
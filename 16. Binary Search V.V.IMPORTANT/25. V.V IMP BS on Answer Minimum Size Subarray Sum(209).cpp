/*
209. Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.


Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

Constraints:
1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).*/


class Solution {
public:
	//check if there exists a subarray of size k which has a sum>=target
	bool blackbox(vector<int>&arr, int target, int k) {
		//first find the first k size subarray sum
		int sum = 0, n = arr.size();
		for (int i = 0; i < k; i++)sum += arr[i];
		//cout<<"1 SUM: "<<sum<<endl;
		int maxi = sum;
		int l = 0, r = k - 1;
		//pointer one at the start of array and 2nd at end subarray of size k so that when sliding the window we subtract from start position and add from last(after size k)
		//Moving the slider
		while (r != n - 1) {
			sum -= arr[l];
			//cout<<"2 SUM: "<<sum<<endl;
			l++;
			r++;
			sum += arr[r];
			//cout<<"3 SUM: "<<sum<<endl;

			maxi = max(maxi, sum);
			//cout<<"4 maxi: "<<maxi<<endl;
		}
		//cout<<(maxi>=target)<<endl;
		return maxi >= target;
	}
	int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
		int low = 1, high = n;
		bool anspossible = false;
		while (low < high) {
			int mid = low + (high - low) / 2;
			//cout<<"1 MID: "<<mid<<endl;
			if (blackbox(nums, target, mid) == true) {
				// cout<<"2 MID: "<<mid<<endl;
				anspossible = true;
				high = mid;
				// cout<<" high: "<<high<<endl;
			}
			else {
				low = mid + 1;
				// cout<<" LOW: "<<low<<endl;
			}
		}
		if (low == high) {
			int mid = low + (high - low) / 2;
			//cout<<"1 MID: "<<mid<<endl;
			if (blackbox(nums, target, mid) == true) {
				//cout<<"2 MID: "<<mid<<endl;
				anspossible = true;
				high = mid;
				//cout<<" high: "<<high<<endl;
			}
			else {
				low = mid + 1;
				//cout<<" LOW: "<<low<<endl;
			}
		}

		if (anspossible == true)return high;
		return 0;
	}
};
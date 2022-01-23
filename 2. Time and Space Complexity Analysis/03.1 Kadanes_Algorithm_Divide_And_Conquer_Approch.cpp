#include<bits/stdc++.h>
using namespace std;

//DIVIDE AND CONQUER APPROCH
// 1. divide array in 2 halfes
// 2. return the max of following
// 	2.1 Max subarray sum in left half (make recursive call)
// 	2.2 Max subarray sum in right half (make recursive call)
// 	2.3 Max subarray sum such that the subarray crosses the midpoint-> can do in linear time
// 	find the max sum starting from mid point and ending at some poinrt to the left of the mid ,
// 	then find maximum sum staring from mid+1 and ending at some point to the right of mid+1.
// 	finally return max of leftSum, rightSum, leftSum+rightSmum

int max(int a, int b) {
	return (a > b) ? a : b;
}

int max(int a, int b, int c) {
	return (max(max(a, b), c));
}

int maxCrossingSum(int arr[], iint l, int m, int h) {
	int sum = 0;
	int left_sum = INT_MIN;
	for (int i = m; i > l; i--) {
		sum += arr[i];
		if (sum > left_sum) {
			left_sum = sum;
		}
	}

	sum = 0;
	int right_sum = INT_MIN;
	for (int i = m + 1; i < h; i++) {
		sum += arr[i];
		if (right_sum < sum) {
			right_sum = sum;
		}
	}

	return (max(left_sum, right_sum, (left_sum + right_sum)));
}

int kadane(int * arr, int l, int h) {
	if (l == h) {
		return arr[l];
	}
	int m = (l + h) / 2;
	return max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int lower,upper = 0;
	cin >> lower;
	int * arr = new int [lower];
	for (int i = 0; i < lower; i++) {
		cin >> arr[i];
	}

	cout << kadane(arr, lower, upper) << endl;


	return 0

}
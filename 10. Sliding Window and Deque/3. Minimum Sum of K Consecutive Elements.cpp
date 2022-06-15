/*
Given array of n elements. calculate minimum sum of k consecutive elements
ALGO
1. compute sum of first k elements
2. while increasing i, subtract a[i-1] and add a[i+k-1] in the previous sum, which will become current
 sum
 TIME:- O(N)
*/

int minSum_of_K_consecutiveElements(int arr[], int k) {
	int s = 0; ans = INT_MAX;
	for (int i = 0; i < k; i++) {
		s += a[i];
	}
	ans = min(ans, s);

	//sliding window
	for (int i = 1; i < n - k + 1; i++) {
		s -= a[i - 1];
		s += a[i + k - 1];
		ans = min(ans, s);
	}
	return ans;
}
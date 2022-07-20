int count_Triplets(vector<int>arr, int r) {
	int n = arr.size();
	unordered_map<long, long>left, right;

	//intializing right map with frequency and left=0
	for (auto x : arr) {
		right[x]++;
		left[x] = 0;
	}

	//compute triplets by iterating from left to right
	int ans = 0;
	for (int i = 0; i < n; i++) {
		right[arr[i]]--;

		if (arr[i] % r == 0) {
			long b = arr[i] / r;
			long a = arr[i];
			long c = arr[i] * r;

			ans += left[b] * right[c];
		}
		left[arr[i]]++;
	}
	return ans;

}
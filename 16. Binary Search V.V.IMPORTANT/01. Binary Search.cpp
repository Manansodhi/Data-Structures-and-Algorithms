//simple binary seacrh on array sorted in ascending order
// time:- O(log2N)


int binarysearch(int arr[], int n, int ele) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == ele)
			return mid;
		else if (arr[mid] > ele)
			end = mid - 1;
		else
			start = mid + 1;
	}
}
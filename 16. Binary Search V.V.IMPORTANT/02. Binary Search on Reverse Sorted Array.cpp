//binary search Reverse Sorted only change is that we have to reverse the else if and else condition
//Time:-O(log2N)

int binarysearchReverseSorted(int arr[], int n, int ele) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == ele)
			return mid;
		else if (arr[mid] > ele)
			start = mid + 1;
		else
			end = mid - 1
		}
}


//Floor of Element in a Sorted Array


int floorOfElement(int arr[], int n, int ele) {
	int start = 0, end = n - 1;
	int res;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == ele)
			return arr[mid];
		if (arr[mid] <= ele) {
			res = arr[mid];
			start = mid + 1;
		}
		else if (arr[mid] >= ele)
			end = mid - 1;
	}
	return res;
}
//Ceil of Element in a Sorted Array

int ceilOfElement(int arr[], int n, int ele) {
	int start = 0, end = n - 1;
	int res;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == ele)
			return arr[mid];
		if (arr[mid] <= ele) {
			start = mid + 1;
		}
		else if (arr[mid] >= ele) {
			res = arr[mid];
			end = mid - 1;
		}
	}
	return res;
}
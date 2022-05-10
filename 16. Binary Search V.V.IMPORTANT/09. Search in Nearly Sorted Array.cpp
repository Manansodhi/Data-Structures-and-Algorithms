//Seacrh eLement in Nearly Sorted array means element is sorted but some element may be displaced from their
 //position either they are present one i-1th, ith, ith+1 index if ith index is the correct position of element

int SearchNearlySortedArray(int arr[], int n, int ele) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == ele)
			return mid;
		if (mid - 1 >= start && arr[mid - 1] == ele)
			return mid - 1;
		if (mid + 1 <= end && arr[mid + 1] == ele)
			return mid + 1;
		else if (arr[mid] >= ele)
			end = mid - 2;
		else
			start = mid + 2;
	}
	return 0;
}

int main() {
	int arr[] = {10, 3, 40, 20, 50, 80, 70};
	int n = sizeof(arr) / sizeof(arr[0]);
	int ele = 40;
	cout << SearchNearlySortedArray(arr, n, ele) << endl;
}
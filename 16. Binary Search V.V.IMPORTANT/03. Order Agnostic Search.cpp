// Order Agnostic Search
//we dont know in which way array is sorted Ascending or descending first we have to find that after
//we have to do searching same as binary search

int binarysearch(int arr[], int n, int ele) {
	int start = 0, end = n - 1;
	bool order;//1->Ascending, 0->Descending
	if (n == 1)
		return (arr[0] == ele) ? 0 : -1;
	if (n > 1)
		order = (arr[0] < arr[1])
		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (order) {
				if (arr[mid] == ele)
					return mid;
				else if (arr[mid] > ele)
					end = mid - 1;
				else
					start = mid + 1;
			}
			else {
				if (arr[mid] == ele)
					return mid;
				else if (arr[mid] > ele)
					start = mid + 1;
				else
					end = mid - 1
				}
		}

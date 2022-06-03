/*Find an element in Bitonic array

Given a bitonic sequence of n distinct elements, and an integer x, the task is to write a program to find given element x in the bitonic sequence in O(log n) time.

A Bitonic Sequence is a sequence of numbers that is first strictly increasing then after a point decreasing.
Input :  arr[] = {-3, 9, 18, 20, 17, 5, 1}, key = 20
Output : Found at index 3

Input :  arr[] = {5, 6, 7, 8, 9, 10, 3, 2, 1}, key = 30
Output : Not Found

Naive Approach: A simple solution is to do a linear search. The time complexity of this solution would be O(n).

Efficient Approach: An efficient solution is based on Binary Search.
Time complexity: O(log n)
Auxiliary Space: O(1)*/


// Function for binary search in ascending part
int ascendingBinarySearch(int arr[], int start,
                          int end, int key)
{
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}


// Function for binary search in
// descending part of array
int descendingBinarySearch(int arr[], int start,
                           int end, int key)
{
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] < key)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}


int findBitonicPoint(int nums[], int n) {
	if (n == 1) return 0; // single element
	// check if 0th/n-1th index is the peak element
	if (nums[0] > nums[1]) return 0;
	if (nums[n - 1] > nums[n - 2]) return n - 1;

	// search in the remaining array
	int start = 1;
	int end = n - 2;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
		else if (nums[mid] < nums[mid - 1]) end = mid - 1;
		else if (nums[mid] < nums[mid + 1]) start = mid + 1;
	}
	return -1; // dummy return statement
}


int searchBitonic(int arr[], int n, int key, int peakEleIdx) {
	if (key > arr[peakEleIdx])
		return -1;
	else if (key == arr[peakEleIdx])
		return peakEleIdx;
	else {
		int temp = ascendingBinarySearch(arr, 0, peakEleIdx - 1, key);
		if (temp != -1) {
			return temp;
		}
		return descendingBinarySearch(arr, peakEleIdx, n - 1, key);
	}
}


int main()
{
	int arr[] = { -8, 1, 2, 3, 4, 5, -2, -3 };
	int key = 1;
	int n, index;
	n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	index = findBitonicPoint(arr, n);

	int x = searchBitonic(arr, n, key, index);

	if (x == -1)
		cout << "Element Not Found" << endl;
	else
		cout << "Element Found at index " << x << endl;

	return 0;
}
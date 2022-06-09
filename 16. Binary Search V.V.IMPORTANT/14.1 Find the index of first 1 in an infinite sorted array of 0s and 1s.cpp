/*
Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array. As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.

Example:
Input : arr[] = {0, 0, 1, 1, 1, 1}
Output : 2

Input : arr[] = {1, 1, 1, 1,, 1, 1}
Output : 0

Let p be the position of element to be searched. Number of steps for finding high index
‘h’ is O(Log p). The value of ‘h’ must be less than 2*p. The number of elements between
h/2 and h must be O(p). Therefore, time complexity of Binary Search step is also O(Log p)
and overall time complexity is 2*O(Log p) which is O(Log p).
*/

int firstOccur(int arr[], int start, int end, int key) {
	int mid = start + (end - start) / 2, res = -1;
	if (arr[mid] == key) {
		res = mid;
		end = mid - 1;
	}
	else {
		start = mid + 1;
	}
	return res;
}


int firstPosition(int arr[], int key) {
	int start = 0, end = 1;
	while (arr[end] < key) {
		start = end;
		end = end * 2;
	}
	return firstOccur(arr, start, end, key);
}

int main() {
	int arr[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,};
	int ans = firstPosition(arr, 1);
	if (ans == -1)
		cout << "Element not found";
	else
		cout << "Element found at index " << ans;
	return 0;
}

//2 Approch

int indexOfFirstOne(int arr[], int low, int high)
{
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
 
        if (arr[mid] == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(low == arr.length)
       return -1;
    return low;
}
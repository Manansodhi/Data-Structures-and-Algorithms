#include<bits/stdc++.h>
using namespace std;



int TimesSortedArrayRotated(int arr[], int n) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		int prev = (mid - 1 + n) % n;
		int next = (mid + 1) % n;

		if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
			return mid;
		else if (arr[mid] <= arr[end])
			end = mid - 1;
		else if (arr[mid] >= arr[start])
			start = mid + 1;

	}
	return 0;
}


int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << TimesSortedArrayRotated(arr,n) << endl;
	return 0;
}
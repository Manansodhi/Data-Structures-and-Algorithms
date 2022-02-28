#include<bits/stdc++.h>
using namespace std;

//search Number for interger data type only
int search(int arr[], int n, int key ) {
	for (int p = 0; p < n; p++) {
		if (arr[p] == key) {
			return p;
		}
	}
	return -1;
}

//search Number any genric data type
// template<class T>  OR
template<typename T>
int search(T arr[], int n, T key ) {
	for (int p = 0; p < n; p++) {
		if (arr[p] == key) {
			return p;
		}
	}
	return -1;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {1, 2, 3, 4, 5, 7, 9};
	int key = 5;
	int n = sizeof(arr) / sizeof(int);
	cout << search(arr, n, key) << endl;

	float b[] = {1.1, 1.2, 1.3};
	float k = 1.3;
	cout << search(b, n, k) << endl;

	return 0;
}
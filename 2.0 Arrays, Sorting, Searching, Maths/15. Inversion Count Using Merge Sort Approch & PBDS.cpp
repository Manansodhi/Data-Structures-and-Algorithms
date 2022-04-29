#include<bit/stdc++.h>
#include<ext/pb_dsassoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//USING POLICY BASED DATA STRUCTURE
//TIME:- O(NLogN)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
	pbds st;
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int inversion_count = 0;
	for (int i = 0; i < n; i++) {
		inversion_count += st.size() - st.order_of_key(arr[i]);
		st.insert(arr[i]);
	}
	return 0;
}


/*
(Enhance Merge Sort)

Approach:
Suppose the number of inversions in the left half and right half of the array (let be inv1 and inv2); what
kinds of inversions are not accounted for in Inv1 + Inv2? The answer is – the inversions that need to be
counted during the merge step. Therefore, to get the total number of inversions that needs to be added are
the number of inversions in the left subarray, right subarray, and merge().

How to get the number of inversions in merge()?
In merge process, let i is used for indexing left sub-array and j for right sub-array. At any step in merge(),
 if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted,
 so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]


Algorithm:
1. The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the
	base case is reached.
2. Create a function merge that counts the number of inversions when two halves of the array are merged, create two
	indices i and j, i is the index for the first half, and j is an index of the second half. if a[i] is greater than
	a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements
	in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
3. Create a recursive function to divide the array into halves and find the answer by summing the number of inversions
	is the first half, the number of inversion in the second half and the number of inversions by merging the two.
4. The base case of recursion is when there is only one element in the given half.
5. Print the answer
*/

// C++ program to Count
// Inversions in an array
// using Merge Sort
#include <bits/stdc++.h>
using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
          int right);

/* This function sorts the
input array and returns the
number of inversions in the array */
int mergeSort(int arr[], int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function
that sorts the input array and
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		/* Divide the array into two parts and
		call _mergeSortAndCountInv()
		for each of the parts */
		mid = (right + left) / 2;

		/* Inversion count will be sum of
		inversions in left-part, right-part
		and number of inversions in merging */
		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);

		/*Merge the two parts*/
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

/* This function merges two sorted arrays
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left, int mid,
          int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			/* this is tricky -- see above
			explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i);
		}
	}

	/* Copy the remaining elements of left subarray
	(if there are any) to temp*/
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	/* Copy the remaining elements of right subarray
	(if there are any) to temp*/
	while (j <= right)
		temp[k++] = arr[j++];

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

// Driver code
int main()
{
	int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int ans = mergeSort(arr, n);
	cout << " Number of inversions are " << ans;
	return 0;
}

/*
Complexity Analysis:

Time Complexity: O(n log n), The algorithm used is divide and conquer, So in each level, one full array traversal is
needed, and there are log n levels, so the time complexity is O(n log n).
Space Complexity: O(n), Temporary array.

Note that the above code modifies (or sorts) the input array. If we want to count only inversions, we need to create a
copy of the original array and call mergeSort() on the copy to preserve the original array’s order
*/
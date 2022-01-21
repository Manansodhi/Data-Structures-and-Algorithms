#include<bits/stdc++.h>
using namespace std;

// //KADANE'S ALGORITHM (LARGEST SUM SUBARRAY)
// //Time:- O(n)
// //this doesnot work when we have all negative numbers
// int kadane(int * arr, int n) {
// 	int current_sum = 0;
// 	int best_sum = 0;
// 	for (int i = 0; i < n; i++) {
// 		current_sum += arr[i];
// 		if (current_sum > best_sum) {
// 			best_sum = current_sum;
// 		}
// 		if (current_sum < 0) {
// 			current_sum = 0;
// 		}
// 	}
// 	return best_sum;
// }

//KADANE's ALGORITHM DP APPROCH
//TIME:- O(n)

int kadane(int * arr, int n) {
	int current_sum = arr[0];
	int best_sum = arr[0];
	for(int i=1;i<n;i++){
		current_sum = max(arr[i],current_sum+arr[i]);
		best_sum=max(best_sum,current_sum);
	}
	return best_sum;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << kadane(arr, n) << endl;

	return 0;
}
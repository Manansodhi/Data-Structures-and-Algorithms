#include "bits/stdc++.h"
using namespace std;

int maxSubArraySum(int arr[], int size){
	int best_sum = 0, curr_sum = 0;
	for (int i = 0; i < size; i++){
		if (arr[i] <= curr_sum + arr[i]){
			curr_sum += arr[i]; 
		}
		else {
			curr_sum = arr[i];
		}
		if (curr_sum > best_sum){
			best_sum = curr_sum;
		}
	}
	return best_sum;
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int size;
	cin >> size;
	int * arr = new int [size];
	for (int i = 0; i < size; i++){
		cin >> arr[i];
	} 

	cout << maxSubArraySum(arr, size) << endl;


	return 0;
}
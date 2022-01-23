#include <bits/stdc++.h>
using namespace std;

//KADANE's ALGORITHM DP APPROCH
//TIME:- O(n)
//This work also well when we have all negative numbers

int kadane(int arr[], int size){
	int best_sum = arr[0], curr_sum = arr[0];
	for (int i = 1; i < size; i++){
		curr_sum = max (arr[i], curr_sum + arr[i]);
		best_sum = max (best_sum, curr_sum);
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

	cout << kadane(arr, size) << endl;


	return 0;
}
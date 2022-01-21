#include<bits/stdc++.h>
using namespace std;

//KADANE'S ALGORITHM 
//Time:- O(n)
int kadane(int * arr, int n){
	int current_sum = 0;
	int best_sum = 0;
	for(int i=0;i<n;i++){
		current_sum+=arr[i];
		if(current_sum>best_sum){
			best_sum=current_sum;
		}
		if(current_sum<0){
			current_sum=0;
		}
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
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << kadane(arr,n) << endl;

	return 0;
}
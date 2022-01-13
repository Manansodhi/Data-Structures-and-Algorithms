#include<bits/stdc++.h>
using namespace std;


//Naive Approch
//Time:- O(N^2)
//Space:- O(1)
//In this we are keeping track of Maximum difference so far and minimum number visited so far
int maxDifference(int arr[], int arrr_size){
	int max_diff = arr[1] - arr[0];
	for (int i = 0; i < arr_size; i++){
		for (int j = 0; j < arr_size; j++){
			if(arr[j] - arr[i] > max_diff){
				max_diff = arr[i] - arr[j];
			}
		}
	}
	return max_diff;
}

//Optimised Approch
//Time:- O(N)
//Space:- O(1)
int maxDifference(int arr[], int arr_size){
	int max_diff = arr[1] - arr[0];
	int min_element = arr[0];

	for (int i = 1; i < arr_size; i++){
		if (arr[i] - min_element > max_diff){
			max_diff = arr[i] - min_element;
		}
		if (arr[i] < min_element){
			min_element = arr[i];
		}
	}
	return max_diff;
}

//like min element we can also keep track of max element from right
//Time:- O(N)
//Space:- O(1)

int maxDifference(int arr[],int arr_size){
	int max_diff = -1;//return negative number when array is sorted in decreasing order and returns 0 if element are equal
	int max_right = arr[arr_size-1];
	for (int i = arr_size - 2; i >= 0; i--){
		if (arr[i] > max_right){
			max_right = arr[i];
		}
		else{
			int diff = max_right - arr[i];
			if (diff > max_diff){
				max_diff = diff;
			}
		}
	}
	return max_diff;
}


//first find difference between 2 adjacent elements and store all diff in axuliary array diff[n-1] 
//and then it become the problem of finding maximum sum subarray of this diff array
//Time:- O(N)
//Space:- O(N)

int maxDifference(int arr[], int arr_size){
	int diff[n-1]; //Auxilary array for storing diff of adjacent element of array
	for (int i = 0; i < arr_size; i++){
		diff[i] = arr[i+1]-arr[i];
	}
	//Now find max sum subarray in "diff" array
	int max_diff = diff[0];
	for (int i = 1; i < n-1; i++){
		if(diff[i-1] > 0){
			diff[i] += diff[i-1];
		}
		if(max_diff < diff[i]){
			max_diff = diff[i];
		}
	}
	return max_diff;
}

// we can make the above code work in O(1) space by calculating difference and max sum in same loop

int maxDifference(int arr[], int arr_size){
	int diff = arr[1]-arr[0];
	int curr_sum =diff;
	int max_diff = curr_sum;
	for(int i = 1; i< n-1; i++){
		max_diff = arr[i+1]-arr[i];
		if(curr_sum > 0){
			curr_sum += diff;
		}
		else{
			curr_sum = diff;
		}
		if(curr_sum >max_diff)
			max_diff = curr_sum;

	}
	return max_diff;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << maxDifference(arr, n) << endl;
	return 0;
}
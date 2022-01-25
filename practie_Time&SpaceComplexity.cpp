#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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

// //KADANE's ALGORITHM DP APPROCH
// //TIME:- O(n)
// //This work also well when we have all negative numbers
// int kadane(int * arr, int n) {
// 	int current_sum = arr[0];
// 	int best_sum = arr[0];
// 	for (int i = 1; i < n; i++) {
// 		current_sum = max(arr[i], current_sum + arr[i]);
// 		best_sum = max(best_sum, current_sum);
// 	}
// 	return best_sum;
// }


// //PRINTING SUBARRAY WITH MAXIMUM SUM
// void kadane(int * arr, int n) {
// 	int best_sum = 0, current_sum = 0, start = 0, end = 0, s = 0;
// 	for(int i =0;i<n;i++){
// 		current_sum +=arr[i];
// 		if(current_sum>best_sum){
// 			best_sum=current_sum;
// 			start=s;
// 			end=i;
// 		}
// 		if(current_sum<0){
// 			current_sum=0;
// 			s=i+1;
// 		}
// 	}
// 	cout<<"Maximum Contignous sum is " << best_sum<<endl;
// 	int size = end-start+1;
// 	for(int i=0;i<size;i++){
// 		cout<<arr[start]<<", ";
// 		start++;
// 	}

// }


// //DIVIDE AND CONQUER APPROCH
// //Time O(nLogn)
// // 1. divide array in 2 halfes
// // 2. return the max of following
// // 	2.1 Max subarray sum in left half (make recursive call)
// // 	2.2 Max subarray sum in right half (make recursive call)
// // 	2.3 Max subarray sum such that the subarray crosses the midpoint-> can do in linear time
// // 	find the max sum starting from mid point and ending at some poinrt to the left of the mid ,
// // 	then find maximum sum staring from mid+1 and ending at some point to the right of mid+1.
// // 	finally return max of leftSum, rightSum, leftSum+rightSmum

// int max(int a, int b) {
// 	return (a > b) ? a : b;
// }

// int max(int a, int b, int c) {
// 	return (max(max(a, b), c));
// }

// int maxCrossingSum(int arr[], int l, int m, int h) {
// 	int sum = 0;
// 	int left_sum = INT_MIN;
// 	for (int i = m; i >= l; i--) {
// 		sum += arr[i];
// 		if (sum > left_sum) {
// 			left_sum = sum;
// 		}
// 	}

// 	sum = 0;
// 	int right_sum = INT_MIN;
// 	for (int i = m + 1; i <= h; i++) {
// 		sum += arr[i];
// 		if (right_sum < sum) {
// 			right_sum = sum;
// 		}
// 	}

// 	return (max(left_sum, right_sum, (left_sum + right_sum)));
// }

// int maxSubArraySum(int * arr, int l, int h) {
// 	if (l == h) {
// 		return arr[l];
// 	}
// 	int m = (l + h) / 2;

//     /* Return maximum of following three possible cases
//             a) Maximum subarray sum in left half
//             b) Maximum subarray sum in right half
//             c) Maximum subarray sum such that the subarray
//        crosses the midpoint */

// 	return (max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h)));
// }


// //K_concatenation
// //Time: O(n)

// ll kadane(int * arr, int n) {
// 	ll curr_sum = 0;
// 	ll best_sum = INT_MIN;
// 	for (int i = 0; i < n; i++) {
// 		curr_sum += arr[i];
// 		best_sum = max(curr_sum, best_sum);
// 		if (curr_sum < 0) {
// 			curr_sum = 0;
// 		}
// 	}
// 	return best_sum;
// }

// ll kCon(int * arr, int n, int k) {
// 	ll kadaneSum = kadane(arr, n);
// 	if (k == 1) {
// 		return kadaneSum;
// 	}
// 	ll curr_prefix_sum = 0, curr_suffix_sum = 0;
// 	ll best_prefix_sum = INT_MIN;
// 	ll best_suffix_sum = INT_MIN;

// 	for (int i = 0; i < n; i++) {
// 		curr_prefix_sum += arr[i];
// 		best_prefix_sum = max(curr_prefix_sum, best_prefix_sum);
// 	}
// 	ll total_sum = curr_prefix_sum;

// 	for (int i = n - 1; i >= 0; i--) {
// 		curr_suffix_sum += arr[i];
// 		best_suffix_sum = max(best_suffix_sum, curr_suffix_sum);
// 	}
// 	ll ans ;
// 	if (total_sum >= 0) {
// 		ans = max((best_suffix_sum + (total_sum * (k - 2)) + best_prefix_sum), kadaneSum);
// 	}
// 	else {
// 		ans = max(best_prefix_sum + best_suffix_sum, kadaneSum);
// 	}
// 	return ans;

// }


// // MAXIMUM PRODUCT SUBARRAY
// //TIME :- O(n)
// //SPACE:- O(1)

// int maxProductSubArray(int * arr, int size){
// 	int max_ending_here = 1, min_ending_here = 1, max_so_far = 0;
// 	for(int i = 0;i<size;i++){
// 		if(arr[i]>0){
// 			max_ending_here = max_ending_here*arr[i];
// 			min_ending_here = min(1,min_ending_here*arr[i]);
// 		}
// 		else if (arr[i] < 0){
// 			int temp = min_ending_here;
// 			min_ending_here = max_ending_here * arr[i];
// 			max_ending_here = max(1,temp*arr[i]);
// 		}
// 		else{
// 			max_ending_here = 1;
// 			min_ending_here = 1;
// 		}
// 		max_so_far = max(max_so_far,max_ending_here);
// 	}
// 	return  max_so_far;
// }


// //MAX BENDING PRODUCT EXPLAIN
// //TIME :- O(N)
// //SPACE :- O(1)

// void mind_bending(int * arr, int n){
// 	long *product = new long int[n];
// 	long lp = 1;
// 	for (int i = 0; i < n; i++) {
// 		product[i] = lp;
// 		lp = lp * arr[i];
// 	}

// 	long rp = 1;
// 	for (int i = n - 1; i >= 0; i--) {
// 		product[i] = product[i] * rp;
// 		rp = rp * arr[i];
// 	}

// 	for (int i = 0; i < n; i++) {
// 		cout << product[i] << " ";
// 	}
// 	cout << endl;
// }


// //ASSIGNMENT QUESTIONS
// // DUPLICATE IN  ARRAY
// // 1. Naive Approch

// //   0 - (n-2) <= values of elements => total (n-1) elements
// //   campare each element of array with remaining n-1, n-2, ....., 1 elements
// //   TIME :- O(n^2)
// //   Space :- O(1)

// // 2. Sorting Approch
// //    sort the array in O(log n) and then compare two consective elements if they are same return that it
// //    will take O(n)
// //    TIME :- O(log n)
// //    Space :- O(1)

// // 3. Optimized Approch
// //    find sum of all elements of array in O(n) time and then also find the sum of first (n-2) natural numbers 
// //    becoz we know that we have elements of array btw 0 - (n-2) it will take O(1)time direct formula   
// //    TIME :- O(n)
// //    Space :- O(1) 

// int duplicate_in_array(int * arr, int size){
// 	//TIME- O(n)
// 	int sum  =0 ;
// 	for(int i = 0;i<n;i++){
// 		sum = sum +arr[i];
// 	}
// 	return (sum - ((size-2)*(size-1)/2));
// }


// //TRIPLET SUM
// // 1. BRUTE FORCE APPROCH
// // TIME O(N^3)

// int Triplet_sum(int * arr, int size, int sum) {
//     int count = 0;
//     for (int i = 0; i < size - 2; i++) {
//         for (int j = i + 1; j < size - 1; j++) {
//             for (int k = j + 1; k < size; k++) {
//                 if (arr[i] + arr[j] + arr[k] == sum) {
//                     count++;
//                 }
//             }
//         }
//     }
//     return count;
//  }


 int Triplet_sum(int * arr, int size, int X){
    int count = 0;
    sort(arr,arr+size);
    int start, end;
    for(int i =0;i<size-2;i++){
        start=i+1;
        end = size-1;
        while(start < end){
            if(arr[i]+arr[start]+arr[end] >X){
                end;
            }
            else if(arr[i]+arr[start]+arr[end]<X){
                start++;
            }
            else{
                count++;
            }
        }
    }
    return count;
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
	//cout << kadane(arr, n) << endl;
	//kadane(arr, n);


	// int upper ;
	// cin >> upper;
	// int * arr = new int [upper];
	// for (int i = 0; i < upper; i++) {
	// 	cin >> arr[i];
	// }

	// cout << maxSubArraySum(arr, 0, upper - 1) << endl;

	// int t;
	// cin >> t;
	// while (t--) {
	// 	int size, k;
	// 	cin >> size >> k;
	// 	int * arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		cin >> arr[i];
	// 	}
	// 	cout << kCon(arr, size, k) << endl;
	// }


	//cout << maxProductSubArray(arr,n) << endl;

	// mind_bending(arr, n);

	// cout << duplicate_in_array(arr, size) << endl;

	 int X ;
     cin >> X;
     cout << Triplet_sum(arr, n, X) << endl;

	return 0;
}
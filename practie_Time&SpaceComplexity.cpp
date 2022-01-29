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
// // TIME O(N^3)  SPACE O(1)

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

// // Approch 2:- Sorting -> 2 pointer technique
// // SPACE :- O(1)
// // TIME :- O(N^2) => Only 2 nested loop traversing array. 2 pointer technique takes O(N)
// // Two pointer technique take linear time better than nested loop
// //  1. sort
// //  2. fix 1rst element of triplet  = arr[i]
// //  3. fix 2 pointer ,at (i+1) amd (n-1) position and look at the sum of triplet
// //    3.1 if sum is smaller than X then increment the pointer
// //    3.2 else if the sum is bigger decrease the end pointer to reduce the sum
// //    3.3 else sum of 2 pointer is equal to X(required sum) then print the triplet

// int Triplet_sum(int * arr, int size, int X) {
// 	int count = 0;
// 	sort(arr, arr + size);
// 	int start, end;
// 	for (int i = 0; i < size - 2; i++) {
// 		start = i + 1;
// 		end = size - 1;
// 		while (start < end) {
// 			if (arr[i] + arr[start] + arr[end] > X) {
// 				end;
// 			}
// 			else if (arr[i] + arr[start] + arr[end] < X) {
// 				start++;
// 			}
// 			else {
// 				count++;
// 			}
// 		}
// 	}
// 	return count;
// }

// int pairSum(int * arr, int start , int end, int num) {
// 	int count = 0;
// 	while (start < end) {
// 		if (arr[start] + arr[end] > num) {
// 			end--;
// 		}
// 		else if ( arr[start] + arr[end] < num) {
// 			start++;
// 		}
// 		else {
// 			int startElement = arr[start];
// 			int endElement = arr[end];

// 			if (startElement == endElement) {
// 				int totalElementsFromStartToEnd = (end - start) + 1;
// 				count += (totalElementsFromStartToEnd * (totalElementsFromStartToEnd -1) / 2);
// 				return count ;
// 			}
// 		}
// 	}
// }


// int Triplet_sum(int * arr, int size, int X) {
// 	sort(arr, arr + size);
// 	int count = 0;
// 	for (int  i = 0; i < size; i++) {
// 		int pairSumfor = X - arr[i];
// 		int numPairs = pairSum(arr, (i + 1), (size - 1), pairSumfor);
// 		count += numPairs;
// 	}
// 	return count;
// }


// //1. Approch Naive
// //TIME :- O(N*D) = O(10^12) =>TLE
// void Rotate_Array_left_By_D_position(int * arr, int size, int d){
//     int temp;
//     while(d--){
//     	temp = arr[0];
//         for(int i = 0; i < size; i++){
//             arr[i] = arr[i+1];
//         }
//         arr[size-1] = k;
//         O()
//     }
//     arr[size-1] = temp;
//     for(int i =0;i <size;i++){
//         cout << arr[i] <<" " ;
//     }
//     cout << endl;
// }

// //2. Approch
// // Every element will be displaced from its current position by d position
// //Time :- O(N)
// //Space :- O(d)
// void Rotate_Array_left_By_D_position(int *arr, int size, int d){
//     int temp[d];
//     for(int i = 0; i <d;i++){
//         temp[i] = arr[i];
//     }

//     for(int i = 0; i < size-d;i++){
//         arr[i] = arr[i+d];
//     }
//     for(int i = size-d,j=0; i< size;i++,j++){
//         arr[i] = temp[j];
//     }
//      for(int i =0;i <size;i++){
//         cout << arr[i] <<" " ;
//     }
//     cout << endl;
// }



// //3. Approch By Reversing the array twice

// void rotator(int *arr, int low, int high) {
//     while (low < high) {
//         swap(arr[low], arr[high]);
//         low++;
//         high--;
//     }
// }

// void Rotate_Array_left_By_D_position(int* arr, int size, int d) {
//     if (d >= size && size != 0)
//         d = d % size; // like the array size is 5 and d=8 so array doesnot get changed in first 5 reverse but effectively get reversed in 3 so (d%size)
//     else if (size == 0)
//         return;
//     rotator(arr, 0, size - 1);
//     rotator(arr, size - d, size - 1);
//     rotator(arr, 0, size - d - 1);
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " " ;
//     }
//     cout << endl;
// }


// //ONE DUPLICATE ELEMENT
//  // Using XOR Operator (bitwise Operator)
//  //    Properties of XOR operator
//  //    X^X = 0
//  //    X^0 = X
//  //   Time :- O(N)
//  //   Space :- O(1)

// int One_Duplicate_Element(int * arr, int size){
// 	int all = 0;
// 	for(int i=0; i<size; i++){
// 		cin >> arr[i];
// 		all ^= arr[i];
// 	}
// 	return all;
// }



// //TWO DUPLICATE ELEMENT
// // TIME :- O(N)
// // SPACE :- O(1)


// bool hasBitSet(int n, int x) {
// 	int tem = n & (1<<x);
// 	return tem!=0;
// }

// void Two_Duplicate_Element(int * arr, int size){
// 	int all = 0;
// 	int ans[2] = {0,0}; // for storing only 2 duplicate element
// 	for(int i=0; i<size; i++){
// 		cin >> arr[i];
// 		all ^= arr[i];
// 	}

// 	/*assert(all != 0);
// 	 This while loop is used to find the right most bit position (Turned ON bit(=1)). if hasSetBit() returns 0 means ki 0th
// 	 position per nahi h right most bit toh k++ kiya and 1rst position per check karega (=1) and it goes on untill it find
// 	  right most bit*/

// 	int k = 0;
// 	while( hasBitSet(all, k) == 0 ) k++;

// 	//int rightbit = all & ~(all-1);

// 	//parition array into two sets: kth bit on v/s off
// 	for (int i=0; i<size; i++) {
// 		"hasBitSet(arr[i], k)" es se bacically ham kya kar rahe h ki Element ka phele right most bit nikal rahe h by (1<<k)
// 		   esme hame jo position choose kari thi right most bit usko left sift kar diya or fir AND(&) operation se pata chal
// 		   ki agar voh dono same h toh hasBitSet() 1 return karega or voh ans[1] m chala jayega element nahi toh ans[0] m
// 		   jayega voh element or sath hi sath XOR operation bhi hoti rahegi har element ki. jase element 6 ->110 and
// 		   k = 0 (becoz ALL = 4^1= 5=101 toh right most bit 0 position per hi milgayi) h toh "hasBitSet(arr[i], k)"
// 		   => hasBitSet(6, 0) => n&(1<<k) => (6&(1<<0))=> (6&1) => (110 & 001)=> 2!=0 toh ye return karega 1. ans[1] ^= arr[i]
// 		   toh jo dono 6 hoge voh ans ke 1 partition m jayege or sath sath m jo bhi element partition m ayega uska sath m XOR
// 		   bhi hota rahega
// 		ans[hasBitSet(arr[i], k)] ^= arr[i];
// 	}

// 	cout << ans[0] << " " << ans[1] << endl;;
// }


// PAIR SUM TO ZERO
// 1. Approch Naive
// Time :- O(N^2)
// search for a number which sum gives 0 with every element of array


// // 2. Approch Optimize
// // Time :- O(N logN)
// // Here we store the frequency of each element in map which will take O(log N) time and then we will traverse the whole array
// //  once to find the element from map which when sum with array element give 0 sum and reduce the frequency from map


// // 3. Using HashMap
// // Time :- O(N)
// // Space :- O(N)
// // In this we are traversing whole array once and we are making pair and maintaing the frequency of each element in hashmap both
// //  at same time

// int Pair_Sum_To_Zero(int *arr, int size){
// 	unordered_map<int, int>freq;
// 	int pairCount = 0;
// 	for(int i =0;i<size;i++){
// 		int complement = -arr[i];
// 		if(freq.find(complement) != freq.end()){
// 			pairCount +=freq[complement];
// 		}
// 		++freq[arr[i]];
// 	}
// 	return pairCount;
// }

// // 2 APPROCH
//  void Pair_Sum_To_Zero(int * arr, int size){
//  	unordered_map<int,int>m1;
//  	for(int i=0;i<size;i++){
//  		if(m1[0-arr[i]]==0){
//  			m1[arr[i]]++;
//  		}
//  		else{
//  			m1[arr[i]]++;
//  		}
//  	}
//  	unordered_map<int,int>::iterator it = m1.begin();
//  	while(it!=m1.end()){
//  		int total=0;
//  		int left = it->second;
//  		int right = m1[-it->first];
//  		total=left*right;
//  		while(total>0){
//  			cout <<min(it->first,-it->first)<<" "<<max(it->first,-it->first)<<endl;
//  			total--;
//  		}
//  		m1[it->first]=0;
//  		m1[-it->first]=0;
//  		it++;
//  	}
//  }


// // 3 APPROCH

// void Pair_Sum_To_Zero(int * arr, int size) {
// 	sort(arr, arr + size);
// 	int starting_position_of_positive_elements = 0;
// 	while (arr[starting_position_of_positive_elements] < 0) {
// 		starting_position_of_positive_elements++;
// 	}
// 	map<int, int> m;
// 	for (int i = starting_position_of_positive_elements; i < size; i++) {
// 		m[arr[i]++];
// 	}
// 	for (int i = 0; i < starting_position_of_positive_elements;  i++) {
// 		int temp = m[-arr[i]];
// 		if (temp > 0) {
// 			while (temp--) {
// 				cout << arr[i] << " " << -arr[i] << endl;
// 			}
// 		}
// 	}
// }


// // Longest Consecutive Sequence
// // 1. Approch Using Sorting
// // Time:- O(N log N)
// // Space:- O(1)

// int Longest_Consecutive_Sequence(int * arr, int size) {
// 	if (size == 0) {
// 		return 0;
// 	}
// 	sort(arr, arr + size);
// 	int ans = 1;
// 	int previous = arr[0];
// 	int curr = 1;
// 	for (int i = 1; i < size; i++) {
// 		if (arr[i] == previous + 1) {
// 			curr++;
// 		}
// 		else if (arr[i] != previous) {
// 			curr = 1;
// 		}
// 		previous = arr[i];
// 		ans = max(ans, curr);
// 	}
// 	return ans;
// }


// // 2. Approch Using HashMap
// // Time:- O(N)
// // Space:- O(N)

// vector<int> Longest_Consecutive_Sequence(int * arr, int size) {
// 	vector<pair<int, int>> pairs_vector;
// 	//In Vector first element of each pair is start and second element is the max_length
// 	map<int, bool>m;
// 	for (int i = 0; i < size; i++) {
// 		m[arr[i]] = true;
// 	}

// 	int max_length=0,start=0;
// 	for(int i=0;i<size;i++){
// 		int curr_len=1;
// 		int curr_start=0;
// 		if(m[arr[i]] == true){
// 			m[arr[i]] = false;

// 			int element_at_position = arr[i];
// 			while(m[element_at_position+1]==true){
// 				curr_len++;
// 				m[element_at_position+1] = false;
// 				element_at_position++;
// 			}

// 			element_at_position = arr[i];
// 			curr_start = element_at_position;
// 			while(m[element_at_position-1]==true){
// 				m[element_at_position-1]=false;
// 				curr_start--;
// 				curr_len++;
// 				element_at_position--;
// 			}
// 		}
// 		if(curr_len>=max_length){
// 			max_length = curr_len;
// 			start = curr_start;
// 			pair<int,int>p;
// 			p.first=start;
// 			p.second = max_length;
// 			pairs_vector.push_back(p);
// 		}

// 		if(max_length==1 && start == arr[size-1]){
// 			vector<int>temp;
// 			temp.push_back(arr[0]);
// 			return temp;
// 		}

// 		for (int i = 0; i < size; i++) {
// 			int starting_element = arr[i];
// 			for (int j = 0; j < pairs_vector.size(); j++) {
// 				if (starting_element == pairs_vector[j].first && max_length == pairs_vector[j].second) {
// 					vector<int> temp;
// 					for (int k = starting_element; k < starting_element + max_length; k++) {
// 						temp.push_back(k);
// 					}
// 					return temp;
// 				}
// 			}
// 		}
// 	 }
// }


// // upar wala code ye 2 case k liye fail hua h
// // Sample Input 2 :
// // 7
// // 3 7 2 1 9 8 41
// // Sample Output 2 :
// // 7 9
// // Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9],
// //  but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will
// //   be 7 9, as we have to print starting and ending element of the longest consecutive sequence.

// // 13
// // 2 12 9 16 10 5 3 20 25 11 1 8 



// // Optimized Approc
// // Time:- O(N)
// // Space:- O(N)


// vector<int> Longest_Consecutive_Sequence(int * arr, int size) {
// 	unordered_map<int, bool>visitedElements;
// 	unordered_map<int, int> elementToIndexMapping;
// 	for(int i=0;i<size;i++){
// 		elementToIndexMapping[arr[i]] = i;

// 		if(visitedElements.count(arr[i]) == 0){
// 			visitedElements[arr[i]] = true;
// 		}
// 	}

// 	vector<int> longestSequence;

// 	int globalMaxSequenceLength = 1;
// 	int globalMinStartIndex = 0;

// 	for(int i=0;i<size;i++){
// 		int num =arr[i];
// 		int currentMinStartIndex = i;
// 		int count = 0,tempNum = num;

// 		while(visitedElements.count(tempNum) == 1 && visitedElements[tempNum] == true){
// 			visitedElements[tempNum] = false;
// 			count++;
// 			tempNum++;
// 		}

// 		tempNum = num-1;
// 		while(visitedElements.count(tempNum)==1 && visitedElements[tempNum] == true){
// 			visitedElements[tempNum] = false;
// 			count++;
// 			currentMinStartIndex=elementToIndexMapping[tempNum];
// 			tempNum--;
// 		}

// 		if(count>globalMaxSequenceLength){
// 			globalMaxSequenceLength = count;
// 			globalMinStartIndex = currentMinStartIndex;
// 		}
// 	}

// 	int globalStartNum = arr[globalMinStartIndex];
// 	longestSequence.push_back(globalStartNum);
// 	if(globalMaxSequenceLength>1){
// 		longestSequence.push_back(globalStartNum+globalMaxSequenceLength-1);
// 	}
// 	return longestSequence;
// }





int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	// int n;
	// cin >> n;
	// int arr[n];
	// for (int i = 0; i < n; i++) {
	// 	cin >> arr[i];
	// }
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

	// int X ;
	// cin >> X;
	// cout << Triplet_sum(arr, n, X) << endl;


	int t;
	cin >> t;

	while (t--) {
		int size;
		cin >> size;
		int arr[size];
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}

//        int d;
//        cin >> d;
//        Rotate_Array_left_By_D_position(arr, size, d);
//    }


		//cout << One_Duplicate_Element(arr, size) << endl;
		//Two_Duplicate_Element(arr, size);

		//cout << Pair_Sum_To_Zero(arr, size) << endl;
		//Pair_Sum_To_Zero(arr, size);

		//cout << Longest_Consecutive_Sequence(arr, size) << endl;
		//Longest_Consecutive_Sequence(arr, size);
		vector<int> ans = Longest_Consecutive_Sequence(arr, size);
		for (auto i = ans.begin(); i != ans.end(); ++i) {
			cout << *i << " ";
		}
		cout << endl;

	}


	return 0;
}
/*
Pair sum to 0
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol
N. The following line contains N space separated integers, that denote the value of the elements of the array.
Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0.
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2--->(2,-2),(-2,2)
Sample Input 2:
7
-2,2,6,-2,2,-6,3
Sample Output 2:
5--->(-2,2),(-2,2),(-2,2),(-2,2),(-6,6)
*/


/*
1. Approch Naive
Time :- O(N^2)
search for a number which sum gives 0 with every element of array
*/

/*
2. Approch Optimize
Time :- O(N logN)
Here we store the frequency of each element in map which will take O(log N) time and then we will traverse the whole array
 once to find the element from map which when sum with array element give 0 sum and reduce the frequency from map
*/

/*3. Using HashMap
Time :- O(N)
Space :- O(N)
In this we are traversing whole array once and we are making pair and maintaing the frequency of each element in hashmap both
 at same time
*/

#include<bits/stdc++.h>
using namespace std;

// 1 APPROCH

int Pair_Sum_To_Zero(int *arr, int size) {
	unordered_map<int, int>freq;
	int pairCount = 0;
	for (int i = 0; i < size; i++) {
		int complement = -arr[i];
		if (freq.find(complement) != freq.end()) {
			pairCount += freq[complement];
		}
		++freq[arr[i]];
	}
	return pairCount;
}

// 2 APPROCH
void Pair_Sum_To_Zero(int * arr, int size) {
	unordered_map<int, int>m1;
	for (int i = 0; i < size; i++) {
		if (m1[0 - arr[i]] == 0) {
			m1[arr[i]]++;
		}
		else {
			m1[arr[i]]++;
		}
	}
	unordered_map<int, int>::iterator it = m1.begin();
	while (it != m1.end()) {
		int total = 0;
		int left = it->second;
		int right = m1[-it->first];
		total = left * right;
		while (total > 0) {
			cout << min(it->first, -it->first) << " " << max(it->first, -it->first) << endl;
			total--;
		}
		m1[it->first] = 0;
		m1[-it->first] = 0;
		it++;
	}
}


// 3 APPROCH
void Pair_Sum_To_Zero(int * arr, int size) {
	sort(arr, arr + size);
	int starting_position_of_positive_elements = 0;
	while (arr[starting_position_of_positive_elements] < 0) {
		starting_position_of_positive_elements++;
	}
	map<int, int> m;
	for (int i = starting_position_of_positive_elements; i < size; i++) {
		m[arr[i]++];
	}
	for (int i = 0; i < starting_position_of_positive_elements; i < size; i++) {
		int temp = m[-arr[i]];
		if (temp > 0) {
			while (temp--) {
				cout << arr[i] << " " << -arr[i] << endl;
			}
		}
	}
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	while (t--) {
		int size;
		cin >> size;
		int arr[size];
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}

		cout << Pair_Sum_To_Zero(arr, size) << endl;
	}
	return 0;
}
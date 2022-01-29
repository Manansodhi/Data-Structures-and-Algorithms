/*
Longest Consecutive Sequence

You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence
of consecutive numbers using the numbers from given array. You need to return the output array which contains starting and ending
 element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.

Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.

Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of longest
consecutive sequence, then just print the starting element.

Constraints :
0 <= n <= 10^6

Time Limit: 1 sec

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6

Sample Output 1 :
8 12

Sample Input 2 :
7
3 7 2 1 9 8 41

Sample Output 2 :
7 9

Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9],
but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be
 7 9, as we have to print starting and ending element of the longest consecutive sequence.

Sample Input 3 :
7
15 24 23 12 19 11 16

Sample Output 3 :
15 16

*/

/*
1. Approch Using Sorting
Time:- O(N log N)
Space:- O(1)
This returns the length of longest consecutive sequence not the start and end position
*/

int Longest_Consecutive_Sequence(int * arr, int size) {
	if (size == 0) {
		return 0;
	}
	sort(arr, arr + size);
	int ans = 1;
	int previous = arr[0];
	int curr = 1;
	for (int i = 1; i < size; i++) {
		if (arr[i] == previous + 1) {
			curr++;
		}
		else if (arr[i] != previous) {
			curr = 1;
		}
		previous = arr[i];
		ans = max(ans, curr);
	}
	return ans;
}


/*
2. Approch Using HashMap
Time:- O(N)
Space:- O(N)
*/

vector<int> Longest_Consecutive_Sequence(int * arr, int size) {
	vector<pair<int, int>> pairs_vector;
	//In Vector first element of each pair is start and second element is the max_length

	map<int, bool>m;
	for (int i = 0; i < size; i++) {
		m[arr[i]] = true;
	}

	int max_length = 0, start = 0;
	for (int i = 0; i < size; i++) {
		int curr_len = 1;
		int curr_start = 0;
		if (m[arr[i]] == true) {
			m[arr[i]] = false;

			//Forward Propagation from arr[i]
			int ele_at_position = arr[i];
			while (m[ele_at_position + 1] == true) {
				curr_len++;
				m[ele_at_position + 1] = false;
				ele_at_position++;
			}

			//Back Propagation from arr[i]
			ele_at_position = arr[i];
			curr_start = ele_at_position;
			while (m[ele_at_position - 1] == true) {
				m[ele_at_position - 1] = false;
				curr_start--;
				curr_len++;
				ele_at_position--;
			}
		}
		if (curr_len >= max_length) {
			max_length = curr_len;
			start = curr_start;
			pair<int, int>p;
			p.first = start;
			p.second = max_length;
			pairs_vectors.push_back(p);
		}
		if (max_length == 1 && start == arr[size - 1]) {
			vector<int>temp;
			temp.push_back(arr[0]);
			return temp;
		}
		for (int i = 0; i < size; i++) {
			int starting_element = arr[i];
			for (int j = 0; j < pairs_vectors.size(); j++) {
				if (starting_element == pairs_vectors[j].first && max_length == pairs_vectors[j].second) {
					vector<int> temp;
					for (int k = starting_element; k < starting_element + max_length; k++) {
						temp.push_back(k);
					}
					return temp;
				}
			}
		}
	}
}

/*
upar wala code ye 2 case k liye fail hua h
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9],
 but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will
  be 7 9, as we have to print starting and ending element of the longest consecutive sequence.

13
2 12 9 16 10 5 3 20 25 11 1 8 6
*/

/*
Time:- O(N)
Space:- O(N)
*/

vector<int> Longest_Consecutive_Sequence(int * arr, int size) {
	unordered_map<int, bool>visiedElements;
	unordered_map<int, int>elementToIndexMapping;

	for (int i = 0; i < size; i++) {
		elementToIndexMapping[arr[i]] = i;

		if (visiedElements.count(arr[i]) == 0) {
			visiedElements[arr[i]] = true;
		}
	}
	vector<int> longestSequence;

	int globalMaxSequenceLength = 1;
	int globalMinStartIndex = 0;

	for (int i = 0; i < size; i++) {
		int num = arr[i];
		int currentMinStartIndex = i;
		int count = 0; int tempNum = num;

		//Forward Propagation
		while (visiedElements.count(tempNum) == 1 && visiedElements[tempNum] == true) {
			visiedElements[tempNum] = false;
			count++;
			tempNum++;
		}

		//Backward Propagation
		tempNum = num - 1;
		while (visiedElements.count(tempNum) == 1 && visiedElements[tempNum] == true) {
			visiedElements[tempNum] = false;
			count++;
			currentMinStartIndex = elementToIndexMapping[tempNum];
			tempNum--;
		}
		if (count > globalMaxSequenceLength) {
			globalMaxSequenceLength = count;
			globalMinStartIndex = currentMinStartIndex;
		}
		else if (count == globalMaxSequenceLength) {
			if (currentMinStartIndex < globalMinStartIndex) {
				globalMinStartIndex = currentMinStartIndex;
			}
		}
	}

	int globalStartNum = arr[globalMinStartIndex];
	longestSequence.push_back(globalStartNum);
	if (globalMaxSequenceLength > 1) {
		longestSequence.push_back(globalStartNum + globalMaxSequenceLength - 1);
	}
	return longestSequence;
}

/*
Time:- O(N)
Space:- O(N)
*/

int longestConsecutive(vector<int>& nums) {
	set<int> hashSet;
	for (int num : nums) {
		hashSet.insert(num);
	}

	int longestStreak = 0;
	for (int num : hashSet) {
		if (!hashSet.count(num - 1)) {
			int currentNum = num;
			int currentStreak = 1;
			while (hashSet.count(currentNum + 1)) {
				currentNum++;
				currentStreak++;
			}

			longestStreak = max(currentStreak, longestStreak);
		}
	}
	return longestStreak;
}


#include<bits/stdc++.h>
using namespace std;


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

		vector<int> ans = Longest_Consecutive_Sequence(arr, size);
		for (auto i = ans.begin(); i != ans.end(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
		delete[] arr;
	}
	return 0;
}
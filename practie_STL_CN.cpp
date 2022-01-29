#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


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
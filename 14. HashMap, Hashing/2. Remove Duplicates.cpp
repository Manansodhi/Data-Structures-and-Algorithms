#include<bits/stdc++.h>
using namespace std;

vector<int> Remove_Duplicate(int arr[], int n) {
	vector<int>output;
	unordered_map<int, bool>seen;

	for (int i = 0; i < n; i++) {
		if (seen.count(arr[i]) > 0) {
			continue;
		}
		seen[a[i]] = true;
		output.push_back(a[i]);
	}
	return output;
}


int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> ans = Remove_Duplicate(arr, n);

	for (auto i : ans) {
		cout << i << "," ;
	}
	cout << endl;

	return 0;
}
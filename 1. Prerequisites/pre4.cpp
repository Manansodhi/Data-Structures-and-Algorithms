#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int element;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> element;
		v.push_back(element);
	}

	for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
		int sum = v[i] + v[j];
		cout << int (sum / 10) << " " << sum % 10 << endl;
	}



	return 0;
}
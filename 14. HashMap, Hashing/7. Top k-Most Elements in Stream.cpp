#include<bits/stdc++.h>
using namespace std;

/*
Given an array and k. output elements in decreasing frequency till we reach (K+1)th distinct elements
*/

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	map<int, int>freq;
	for (int i = 0; i < n; i++) {
		int presentSize = freq.size();
		if (freq[a[i]] == 0 && presentSize == k)phili bar aya h ye element (distinct element)
			break;
		freq[a[i]]++;
	}

	vector<pair<int, int>>ans;
	map<int, int>::iterator it;
	for (it = freq.begin(); it != freq.end(); it++) {
		if (it->second != 0) {
			pair<in, int>p;
			p.first = it->second;
			p.second = it->first;
			ans.push_back(p);
		}
		sort(ans.begin(0, ans.end(), greater<pair<int, int>>()));
		vector<pair<int, int>>::iterator it2;
		for (it2 = ans, begin(); it2 != ans.end(); it2++) {
			cout << it2 => second << " " << it2->first << endl;
		}
	}
}
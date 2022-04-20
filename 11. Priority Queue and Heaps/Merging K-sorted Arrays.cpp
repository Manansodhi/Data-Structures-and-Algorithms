#include<bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin >> k;
	vector<vector<int> > a(k);
	for (int i = 0; i < k; i++) {
		int size;//size of each array
		cin >> size;

		a[i] = vector<int>(size);
		for (int j = 0; j < size; j++) {
			cin >> a[i][j];
		}
	}

	vector<int>idx(k, 0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
	//ye starting m har array se phele phele element utha liya
	for (int i = 0; i < k; i++) {
		pair<int,int>p;
		p.first=a[i][0];
		p.second=i;
		pq.push(p);
	}
	vector<int> ans;
	while (!pq.empty()) {
		pair<int, int> x = pq.top();
		pq.pop();
		ans.push_back(x.first);
		if (idx[x.second] + 1 < a[x.second].size()) {
			//ye wala voh case h jab abhi array m element bache hue agar ulta hota toh matlab index wale array
			//me voh array size bada index store kiya hua jisper ja nahi sakte
			 pair<int,int>p;
 			 p.first=a[x.second][idx[x.second] + 1];
 			 p.second=x.second;
			pq.push(p);
		}
		idx[x.second] += 1;
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	cout << endl;


	return 0;
}
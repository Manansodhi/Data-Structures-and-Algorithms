#include<bits/stdc++.h>
using namespace std;
/*
input:
We are learning about STL strings. STL string claa is quite powerfull
STL
ouput:
22 , 35

TIME:- O(n^2)
SPACE:- O(1)

*/
vector<int>stringSearch(string s, string word) {
	vector<int>result;
	int index = s.find(word);
	while (index != -1) {
		result.push_back(index);
		index = s.find(word, index + 1);
	}
	return result;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	getline(cin, s);
	string word;
	getline(cin, word);
	vector<int> ans = stringSearch(s, word);
	for (auto v : ans) {
		cout << v << ",";
	}
	cout << endl;



	return 0;
}
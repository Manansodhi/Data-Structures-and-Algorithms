#include<bits/stdc++.h>
using namespace std;

/*
Input:
abc
Output:
" ", a, b, c, ab, ac, bc, abc

Optimized Using Recursion
TIME:- O()
SPACE:- O()


Using Bit masking
*/

void Subsequence(string s, string o, vector<string> &v) {
	//base case
	if (s.size() == 0) {
		v.push_back(o);
		return;
	}

	//Recursive case
	char ch = s[0];
	string reduced_input = s.substr(1);

	//includes
	Subsequence(reduced_input, o + ch, v);

	//excludes
	Subsequence(reduced_input, o, v);
}

bool compare(string s1, string s2) {
	if (s1.length() == s2.length()) {
		return s1 < s2;
	}
	return s1.length() < s2.length();
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	vector<string> v;
	string output = " ";
	Subsequence(s, output, v);
	sort(v.begin(), v.end(), compare);
	for (auto it : v) {
		cout << it << ",";
	}
	cout << endl;

	return 0;
}
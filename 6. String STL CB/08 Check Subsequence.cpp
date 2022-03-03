#include<bits/stdc++.h>
using namespace std;

/*
INPUT :-
NOTE-> No spaces in between
codingminutes   length=M
cines			length=N

OUTPUT:-
yes

Naive
TIME:- O(2^N * N) for Generating all subset and some more time for matching if any string matches from subset

Optimized
TIME:- O(M+N)
SPACE:- O(1)

2-Pointer Approch

*/

bool checkSubsequence(string s1, string s2) {
	int m = s1.length(), n = s2.length();
	int j = n;
	for (int i = m; i >= 0; i--) {
		if (s1[i] == s2[j]) {
			j--;
		}
	}
	if (j == -1) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1, s2;
	cin >> s1 >> s2;
	cout << checkSubsequence(s1, s2) << endl;

	return 0;
}
#include<bits/stdc++.h>
using namespace std;


/*
input:- hello world sam
output:- hello%20world%20sam

time:- O(length of string)
space:- O(1)

*/

void space20(char* s) {
	int countSpace = 0, additionalSpace = 0;
	for (int itr = 0; s[itr] != '\0'; itr++) {
		if (s[itr] == ' ') {
			countSpace++;
		}
	}
	additionalSpace = (3 * countSpace) - countSpace;
	s[strlen(s) + additionalSpace] = '\0';
	for (int itr = strlen(s) - 1 + additionalSpace, j = strlen(s) - 1; j >= 0; j--) {
		if (s[j] == ' ') {
			s[itr] = '0';
			s[itr - 1] = '2';
			s[itr - 2] = '%';
			itr -= 3;
		}
		else {
			s[itr] = s[j];
			itr--;
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char s[1000];
	cin.getline(s, 1000);
	space20(s);
	cout << s;

	return 0;
}
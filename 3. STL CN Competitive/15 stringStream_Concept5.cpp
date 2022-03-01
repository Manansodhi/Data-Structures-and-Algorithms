#include"bits/stdc++.h"
using namespace std;

/*
find words which are greater than given length k using string stream
input
str = "hello geeks for geeks is computer science portal"
k = 4
output
hello geeks geeks computer science portal
*/

void stringGreaterThanLength_K(string s, int k) {
	string w = " ";
	for (int  i = 0; i < s.size(); i++) {
		if (s[i]! = ' ')
			w = w + s[i];

		else {
			if (w.size() > k) {
				cout << w << " ";
				w = " ";
			}
		}
	}
}


/*
Now using string stream
the idea is to create stream by splitting the given string into tokens and then process the stream and print the words with length
greater than k
*/

void stringGreaterThanLength_K(string str, int k) {
	string word;
	stringstream ss(str);
	int count = 0;
	while (ss >> word) {
		//reading 1 by 1 word stream object into word
		if (word.size() > k) {
			cout << word;
			count ++;
		}
	}
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s ;
	/* cin >> s; wiil not worl becoz will not take input after space
	getline() stream classes support line-oriented functions, getline() & write() to perform input and output functions
	respectively. getline() function reads whole line of text that ends with delimeter("\n", " ")
	*/
	getline(cin, s);
	stringGreaterThanLength_K(s);


	return 0;
}
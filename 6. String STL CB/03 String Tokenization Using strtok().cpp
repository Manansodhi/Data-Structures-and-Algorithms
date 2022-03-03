#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*String Tokenization used to break string into list of token
	Internally
	char * strtok(char * s, char * delimeter) -> returns character pointer, accept char array, also accept array of
	delimeter(about which we want to break the string)
	1.returns a token on each subsequent call
	2.on the first call function should be passed with string argument for 's'
	3.on subsequent calls we should pass the string argument as null

	*/

	char s[100] = "Today is a rainy day";
	char *ptr = strtok(s, " ");
	cout << ptr << endl; // will get the first word

	ptr = strtok(s, " "); //call again
	cout << ptr << endl; // will again get the first string

	/*ptr points to the first token in the string but when we want to get the next token of the string. we will
	pass "NULL" instead of string s when we pass Null in strtok(NULL,' ') maintains the static array that stores the
	state of string(means after first call with string s it knows that it has covered "today" and jumps to next token )*/

	ptr = strtok(Null, " "); //call again
	cout << ptr << endl;


	char *ptr = strtok(s, " ");
	cout << ptr << endl;

	while (ptr != NULL) {
		ptr = strtok(NULL, " ");
		cout << ptr << endl;
	}


	return 0;
}
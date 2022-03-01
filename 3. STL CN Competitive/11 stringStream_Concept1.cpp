#include"bits/stdc++.h"
using namespace std;

/*
 stringStream -> Associates string object with a stream allowing you to read from string as if it were a stream(like cin)
1. clear()-> to clear stream
2. str()-> to get and set string object whose content is present in stream
3. << (operator) -> add a string to the stringStream object
4. >>(operator) -> read something from the stringStream object

stringStream class is extremely usefull in passing input
*/


//Count no of words in string
int countWords(string str) {
	//breaking input into word using stringStream
	stringstream s(str); // Used for breaking words
	string word; //to store indivdual words
	int count = 0 ;
	while (s >> word) {
		// s >> word -> reading string(word) from stringstream object(s)
		count++;
	}
	return count;
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
	cout << countWords(s) << endl;


	return 0;
}
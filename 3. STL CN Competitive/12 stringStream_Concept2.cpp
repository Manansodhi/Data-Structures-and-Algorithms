#include<bits/stdc++.h>
using namespace std;

/*
 stringStream -> Associates string object with a stream allowing you to read from string as if it were a stream(like cin)
1. clear()-> to clear stream
2. str()-> to get and set string object whose content is present in stream
3. << (operator) -> add a string to the stringStream object
4. >>(operator) -> read something from the stringStream object

stringStream class is extremely usefull in passing input
*/


//Print frequency of individual words in a string

void PrintFrequency(string str) {
	//each word is mapped to its frequency
	map<string, int> freq;
	stringstream ss(str); // ss -> object of stringstream str -> input string
	string words;
	while (ss >> words) {
		//Extracting word by word from stream object ss into words(string) till end
		freq[words]++;
	}
	for (auto i : freq) {
		cout << i.first << ":" << i.second << endl;
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
	PrintFrequency(s);


	return 0;
}
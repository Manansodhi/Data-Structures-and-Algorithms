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


/*
Removing Spaces from a string using stringstream USING STL

APPROCH 1
1. Enter the whole string into stringstream.
2. Empty the string.
3. Extract word by word and concatenate to the string.
*/


string removeSpace(string str)
{
	stringstream ss;
	string temp;

	// Storing the whole string into string stream
	ss << str;

	// Making the string empty
	str = "";

	// Running loop till end of stream
	while (!ss.eof()) {

		// Extracting word by word from stream
		ss >> temp;

		// Concatenating in the string to be returned
		str = str + temp;
	}
	return str;
}

/*
1. extracts character up yo delimeter
2. stores character in the buffer
3. maximum no of characters extracted is size-1

The delimeter character is read but not saved into a buffer ,instead it is replaced by the null character
cin.getline(str,20) -> reads a string until it encounters the new line character or maximum no of character

APPROCH 2
*/

string removeSpace(string str) {

	// Storing the whole string into string stream
	stringstream ss(str);
	string temp;
	str = " ";  //Making string empty

	//running loop till the end of stream and getting every word
	while (getline(ss, temp, ' ')) {

		//concatenating in the string to be returned
		str = str + temp;
	}
	return str;
}


/*
TIME :- O(N)
The idea is to keep track of control of non-space character seen so far
APPROCH 3
1. count = 0 (count of non-space character seen so far)
2. iterate through all character of given string
	2.1 if cuurent charcter is non space then put this character at index 'count' and increment 'count'
3. finally put '\0' at the index 'count'
*/


string removeSpace(string str) {
	int count = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] != ' ') {
			str[count] = str[i]
			             count++;
		}
		str[count] = '\0';
	}
	return str;
}


//APPROCH 4 Function to remove all spaces from a given string
string removeSpaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}


//APPROCH 5
string removeSpace(string s) {
	int l = s.length();
	int c = count(s.begin(), s.end(), ' '); // counting nmber of whitespaces
	remove(s.begin(), s.end(), ' '); //removing whitespaces
	s.resize(l - c);
	return s;
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
	cout << removeSpace(s) << endl;


	return 0;
}
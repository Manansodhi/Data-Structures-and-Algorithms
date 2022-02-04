#include<bits/stdc++.h>
using namespace std;

// Coverting strings to numbers
int main() {
	string s = "12345";

	//object from the class stringstream
	stringstream geek(s);

	//object has value 12345 and stream it to the integer x
	int x = 0;
	geek >> x;

	cout << "value of x :" << x << endl;

	// A stringstream is similar to input/output file stream. We need to declare a stringstream just like an fstream, for example:
	stringstream ss;

	// and, like an fstream or cout, we can write to it:
	ss << myString; or
	ss << myCstring; or
	ss << myInt; , or float, or double, etc.

	// and we can read from it:
	ss >> myChar; or
	ss >> myCstring; or
	ss >> myInt;

	// String conversion using stoi() or atoi()
	// stoi() : The stoi() function takes a string as an argument and returns its value. Following is a simple implementation:

	string str1 = "45";
	string str2 = "3.14159";
	string str3 = "31337 geek";

	int myint1 = stoi(str1);
	int myint2 = stoi(str2);
	int myint3 = stoi(str3);

	cout << "stoi(\"" << str1 << "\") is " << myint1 << '\n';
	cout << "stoi(\"" << str2 << "\") is " << myint2 << '\n';
	cout << "stoi(\"" << str3 << "\") is " << myint3 << '\n';
	/*
	OUTPUT
	stoi("45") is 45
	stoi("3.14159") is 3
	stoi("31337 geek") is 31337
	*/

	//atoi() : The atoi() function takes a character array or string literal as an argument and returns its value. Following is a
	//simple implementation:

	const char* str1 = "42";
	const char* str2 = "3.14159";
	const char* str3 = "31337 geek";

	int num1 = atoi(str1);
	int num2 = atoi(str2);
	int num3 = atoi(str3);

	cout << "atoi(\"" << str1 << "\") is " << num1 << '\n';
	cout << "atoi(\"" << str2 << "\") is " << num2 << '\n';
	cout << "atoi(\"" << str3 << "\") is " << num3 << '\n';

	/*
	OUTPUT
	atoi("42") is 42
	atoi("3.14159") is 3
	atoi("31337 geek") is 31337
	*/


	/*
	stoi() vs atoi()

	atoi() is a legacy C-style function. stoi() is added in C++ 11.

	atoi() works only for C-style strings (character array and string literal), stoi() works for both C++ strings and C style
	strings. atoi() takes only one parameter and returns integer value.

	int atoi (const char * str);

	stoi() can take upto three parameters, the second parameter is for starting index and third parameter is for base of input
	number.

	int stoi (const string&  str, size_t* index = 0, int base = 10);
	*/


	return 0;
}

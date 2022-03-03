#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	string s0;
	string s1("Hello");
	string s2 = "Hello World";
	string s3(s2);
	string s4 = s3;


	//for accepting the paragraph that is terminated by "."
	/*input :			output:
	hello 					hello
	world					world
	how are you.			how are you
	*/
	getline(cin, s, '.');
	cout << s << endl;
	//styring object from array
	char a[] = {'a', 'b', 'c', '\0'};
	string s5(a);

	cout << s0 << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

	if (s0.empty()) {
		cout << "Empty String" << endl;
	}

	//Appending Strings
	s0.append("I love C++");
	cout << s0 << endl;
	s0 += " and Python";
	cout << s0 << endl;
	cout << s0.length() << endl;
	s0.erase();
	cout << s0.length() << endl;

	//Comparing two Strings
	s0 = "apple";
	s1 = "mango";
	cout << s0.compare(s1) << endl;
	cout << s1.compare(s0) << endl;
	cout << s0.compare(s0) << endl;

	//overloading ">"
	if (s1 > s0) {
		cout << "mango is lexiographical greater than apple" << endl;
	}

	//find Substring
	string s = "i want to have apple juice";
	int idx = s.find("apple");
	cout << idx << endl;


	//if we are finding substring that is not present in string then it will return that index which is too
	//large (largest number for unsigned long integer value) this integer gets converted to -1 when converted
	//to signed integer

	string paragraph = "We are learning about STL strings. STL string claa is quite powerfull";
	string word;
	getline(cin, word);

	int index = paragraph.find(word);
	if (index != -1) {
		cout << "first Occurence" << index << endl;
	}

	index = paragraph.find(word, index + 1);
	if (index != -1) {
		cout << "Second Occurence" << index << endl;
	}

	// Remove word from string
	string word = "apple";
	int len  = word.length();
	s.erase(idx, len + 1);
	cout << s << endl;

	//iterate over all the character in string
	for (int i = 0 ; i < s1.length(); i++) {
		cout << s1[i] << ".";
	}
	cout << endl;

	//for each loop
	for (auto it : s1) {
		cout << it << ":";
	}
	cout << endl;

	//iterators
	for (auto it = s1.begin(); it != s1.end(); it++) {
		cout << (*it) << endl;
	};


	return 0;
}
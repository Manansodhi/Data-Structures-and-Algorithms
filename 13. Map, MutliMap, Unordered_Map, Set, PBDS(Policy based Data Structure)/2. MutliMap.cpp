#include<bits/sydc++.h>
using namespace std;

//MultiMap have multiple keys that have same values
//insert(), find(), erase() -> O(LogN) becoz underlying data structure is Self Balancing BST


/*input
b batman
a apple
b boot
a angry
c cat
d dog
e elephant
like this multiple values have same keys
*/

/*
output - sorted lexigraphic
a->apple
a->angry
b->batman
b->boat
c->cat
d->dog
e->elephant
*/

int main() {
	multimap<char, string> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch;
		string s;
		cin >> ch >> s;
		m.insert(make_pair(ch, s))''
	}

	for (auto p : m) {
		cout << p.first << "->" << o.second << endl;
	}

	//erasing particular key(will erase apple)
	auto it = m.begin();
	m.erase(it);

	auto it2 = m.lower_bound('b'); //wiil give iterator of batman
	auto it3 = m.upper_bound('d'); //will give iterator of elephant

	for (auto it4 = it2; it4 != it3; it4++) {
		cout << it4->second << "," << endl;
	}
	// output
	// batman
	// boat
	// cat
	// dog

	auto f = m.find('c'); //O(LogN)
	if (f->second == "cat") {
		m.erase(f);
	}

	return 0;
}
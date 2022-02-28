#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<unordered_map>
using namespace std;



int main() {

	//Pair

	pair<int, char> p;
	p = make_pair(2, 'b');
	pair<int, char> p2(1, 'a');
	cout << p.first << " " << p.second << endl;
	cout << p2.first << " " << p2.second << endl;


	//Set

	set<int> s;
	int arr[] = {1, 2, 3, 4, 5, 6, 5};

	for (int i = 0; i < 7; i++) {
		s.insert(arr[i]);
	}

	set<int>::iterator it;

	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}

	if (s.find(7) == s.end()) {
		cout << "Element not found" << endl;
	} else {
		cout << "Element found" << endl;
	}


	// Map

	int arr[] = {1, 2, 3, 4, 5, 6, 5};
	unordered_map<int, int> m;

	for (int i = 0; i < 7; i++) {
		m[arr[i]] = m[arr[i]] + 1;
	}

	unordered_map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		cout << it->first << " :" << it->second << endl;
	}
	cout << endl;
	m.erase(1);
	for (it = m.begin(); it != m.end(); it++) {
		cout << it->first << " :" << it->second << endl;
	}



	return 0;
}
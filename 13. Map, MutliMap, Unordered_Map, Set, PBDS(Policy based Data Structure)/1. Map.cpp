#inculde<bits/stdc++.h>
using namespace std;

int main() {
	map<string, int> m;
	//insertion
	m.insert(make_pair("Mango", 100));
	pair<string, int> p;
	p.first = "Apple";
	p.second = 120;
	m.insert(p);

	m["Banana"] = 20;

	//search
	string fruit;
	cin >> fruit;
	auto it = m.find(fruit);
	//OR
	//map<string, int> :: iterator it;

	if (it != m.end()) {
		cout << "Price of" << fruit << "is" << m[fruit] << endl;
	}
	else {
		cout << "Fruit is not Present" << endl;
	}

	//COUNT() => Amother way to find particular key in map(map stores unique keys Once only)
	//count() works same as find() only difference is that find() returns iterator and count() returns integer(0/1)
	if (m.count(fruit)) {
		cout << "Price of" << fruit << "is" << m[fruit] << endl;
	}
	else {
		cout << "Fruit is not Present" << endl;
	}

	//m.erase(fruit);
	//update
	m[fruit] + 22;
	m["Litchi"] = 60;
	m["Pineapple"] = 80;

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " and " << it->second << endl;
	}

	// for (auto p:m){
	// 	cout<<p.first<<" and " <<p.second<<endl;
	// }

	return 0;

}
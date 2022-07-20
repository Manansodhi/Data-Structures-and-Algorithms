#include<bits/stdc++.h>
using namespace std;



int main() {
	unordered_map<string, int>ourMap;

	//insert
	pair<string, int>p ("abc", 1);
	ourMap.insert(p);

	ourMap["def"] = 2;

	//find or Access

	cout << ourMap["abc"] << endl;
	cout << ourMap.at("abc") << endl;
	cout << ourMap["def"] << endl;

	cout << "Size: " << ourMap.size() << endl;
	//This will show error
	//cout<<ourMap.at("ghi")<<endl;
	cout << ourMap["ghi"] << endl;
	cout << "Size: " << ourMap.size() << endl;


	//check presence
	if (ourMap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

	//erase
	ourMap.erase("ghi");
	cout << "Size: " << ourMap.size() << endl;
	if (ourMap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}
	else {
		cout << "ghi is being erased" << endl;
	}

	return 0;
}
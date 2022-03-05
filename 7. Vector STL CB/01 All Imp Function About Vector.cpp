#include<bits/stdc++.h>
using namespace std;




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>a;
	vector<int>b(5, 10);
	vector<int>c(5, 0);
	vector<int>d(b.begin(), b.end());
	vector<int>e{1, 2, 3, 4, 5};

	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for (auto it = b.begin(); it != b.end(); it++) {
		cout << (*it) << ",";
	}
	cout << endl;

	for (auto x : c) {
		cout << x << ",";
	}
	cout << endl;

	for (auto x : d) {
		cout << x << ",";
	}
	cout << endl;

	for (auto x : e) {
		cout << x << ",";
	}
	cout << endl;

	vector<int>v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int no;
		cin >> no;
		v.push_back(no);
		//O(1) most of time but may take more time when expanding the memory
		//v.pop_back() --> O(1)
	}

	for (auto x : v) {
		cout << x << ",";
	}
	cout << endl;


	/*
	vector v & e both have 5 elements so we have to understand at memeory level what are the differences in two

	*/
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	//8 becoz when we have inserted 4 number it doubles in array linearly
	cout << v.max_size() << endl;
	//maximum number of elememts a vector can held in worst case acc to available memory in the system
	cout << e.size() << endl;
	cout << e.capacity() << endl;
	//5 in this we have intialized e vector in starting that it will only contain 5 elements
	cout << e.max_size() << endl;


	//insert() --> O(N) where N no of elements added + no of elements shifted
	c.insert(c.begin() + 3, 100);
	for (auto x : c) {
		cout << x << ",";
	}
	cout << endl;

	d.insert(d.begin() + 3, 4, -10);
	for (auto x : d) {
		cout << x << ",";
	}
	cout << endl;

	d.erase(d.begin() + 2);
	for (auto x : d) {
		cout << x << ",";
	}
	cout << endl;

	d.erase(d.begin() + 2, d.begin() + 4);
	for (auto x : d) {
		cout << x << ",";
	}
	cout << endl;

	cout << d.size() << endl; //6
	cout << d.capacity() << endl;
	//10 becoz we have inserted element so when added 5th element it increases its capacity to 10and vector doesnot shrink when we erase
	//some element
	d.resize(8);
	for (auto x : d) {
		cout << x << ",";
	}
	cout << endl;
	//resize may or may not change underlying size of arrayand size will change if size increases(more memory will be allocated)
	cout << d.capacity() << endl; //10


	cout << d.front() << endl;
	cout << d.back() << endl;

	//remove all the element of vector, dosenot delete the memory occupied by the array
	d.clear();
	cout << d.size() << endl;

	cout << d.empty() << endl;


	/*Reserve(size of memory to reserve in advance)
	 drawback of vector is that it increases its size by doubling its size when it get full as doubling is expensive operation so to
	 avoid doubling we will reserve around 1000 elements in begining onlyif crosses 1000 element then only new memory will be allocated
	*/

	int n1;
	cin >> n1;
	vector<int>v1;
	v1.reserve(1000);
	for (int i = 0; i < n1; i++) {
		int no;
		cin >> no;
		v1.push_back(no);
	}

	for (auto x : v1) {
		cout << x << ",";
	}
	cout << endl;

	return 0;
}
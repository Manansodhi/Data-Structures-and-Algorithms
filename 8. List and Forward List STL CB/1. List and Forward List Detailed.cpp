#include<bits/stdc++.h>
using namespace std;



/*
LIST :- underlying data structure is doubly linked list so movement in both direction is possible and push nad pop from both front and 
back is possible in only O(1) time we can also insert and erase element from any position becouse it only has connect the node in between 
by taking perivious and next element address
whereas in FORWARD LIST :- it has underlying data structure as singly linked list which can move in forward dirction only and it only 
stores the address of its next node. FORWARD_LIST performs better than array, vector, deque in INSERTING, EXTRACTING AND MOVING elements 
in any position with in the container
DRAWBACK :- direct access not possible 
*/

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	list <int> l;
	list <int>l1 {1, 2, 3, 4, 5, 6};
	list<string>l2 {"apple", "guava", "mango", "bananna"};

	l2.push_back("pineapple");

	for (auto s : l2) {
		cout << s << "-->";
	}
	cout << endl;

	l2.sort();
	cout << "Sorted" << endl;
	for (auto s : l2) {
		cout << s << "-->";
	}
	cout << endl;

	l2.reverse();
	cout << "reversed" << endl;
	for (auto s : l2) {
		cout << s << "-->";
	}
	cout << endl;

	cout << "Front element : " << l2.front() << endl;
	l2.pop_front();
	cout << "After Popping front element" << endl;
	for (auto s : l2) {
		cout << s << "-->";
	}
	cout << endl;

	cout << "Pushing at front" << endl;
	l2.push_front("kiwi");
	//iterating thru iterator
	for (list<string>::iterator it = l2.begin(); it != l2.end(); it++) {
		cout << (*it) << "-->";
	}
	cout << endl;

	cout<<"Adding some fruits at the end"<<endl;
	l2.push_back("orange");
	l2.push_back("lemon");
	for (auto s : l2) {
		cout << s << "-->";
	}
	cout << endl;


	cout << "Removing fruit by value" << endl;
	/*if list have same multiple element and we remove one element then all the occurence of that element will be removed from list */
	string f;
	cin >> f;
	l2.remove(f);
	for (auto s:l2){
		cout<<s<<"-->";
	}
	cout<<endl;


	cout<<"Erasing one or more elements from list"<<endl;
	/*as we know that list has internally implemented as doubly linked list and that doesnot have continous memory allocation for its 
	 each node so direct access of element from list is not allowed so we cannot this to remove element from list
	 auto it = l2.begin()+3;  we can not go to 3rd element from begin by doing l2.begin()+3 becoz of its non-continous memory 
	 l2.erase(it);
	*/

	auto it1 = l2.begin();
	it1++;
	it1++;
	l2.erase(it1);
	for (auto s:l2){
		cout<<s<<"-->";
	}
	cout<<endl;


	cout <<"Inserting elements in the list at any position" << endl;
	auto it3 = l2.begin();
	it3++;
	l2.insert(it3,"fruit juice");
	for (auto s:l2){
		cout<<s<<"-->";
	}
	cout<<endl;


	return 0;

}
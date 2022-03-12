#include<bits/stdc++.h>
using namespace std;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stack<int> s;
	for (int i = 0; i < 5; i++) {
		s.push(i); //O(1) time
	}

	while (!s.empty()) {
		cout << s.top() << ", "; //O(1) time
		s.pop();  //O(1) time
	}
	cout << endl;

	queue<int> q;
	for (int i = 0; i < 5; i++) {
		q.push(i); //O(1) time
	}

	while (!q.empty()) {
		cout << q.front() << ", "; //O(1) time
		q.pop();  //O(1) time
	}
	cout << endl;


	return 0;

}
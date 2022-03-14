#include<bits/stdc++.h>
using namespace std;

// Approch 1 Using one extra stack
// Space: O(N)

// Approch 2 Using Recursion
// Space: O(1)

void insertAtBottom(stack<int> &st, int ele) {
	if (st.empty()) {
		st.push(ele);
		return;
	}
	int top_ele = st.top();
	st.pop();
	insertAtBottom(st, ele);
	st.push(top_ele);
}

void reverse(stack<int> &st, int ele) {
	//Base case
	if (st.empty()) {
		return;
	}

	int ele = st.top();
	st.pop();
	reverse(st);
	insertAtBottom(st, ele);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(30);
	s.push(50);

	reverse(s);
	cout << "Stack After Reversing: ";
	while (!s.empty()) {
		cout << s.top() << ", ";
		s.pop();
	} cout << endl;


	return 0;

}
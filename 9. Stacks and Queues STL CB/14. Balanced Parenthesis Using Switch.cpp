#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string input) {
	stack<char> st;
	for (auto ch : input) {
		switch (ch) {
		case '(':
		case '{':
		case '[': st.push(ch);
			break;
		case ')':
			if (!st.empty() and st.top() == '(') {
				st.pop();
			}
			else {
				return false;
			}
			break;
		case '}':
			if (!st.empty() and st.top() == '{') {
				st.pop();
			}
			else {
				return false;
			}
			break;
		case ']':
			if (!st.empty() and st.top() == '[') {
				st.pop();
			}
			else {
				return false;
			}
			break;
		default: continue;
		}
	}

	if (st.empty()) {
		return true;
	}
	return false;
}



int main() {
	string s = "((a+b+c)+[d])";
	//{a+(b+c)+([d+e]*f))}+k

	if (isBalanced(s)) {
		cout << "Balanced!" << endl;
	}
	else {
		cout << "Not Balanced!" << endl;
	}

	return 0;
}
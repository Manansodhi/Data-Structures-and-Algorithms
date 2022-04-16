#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string input) {
	int n = input.size();
	stack<char> st;
	bool ans = true;
	for (int i = 0; i < n; i++) {
		if (input[i] == '{' or input[i] == '[' or input[i] == '(') {
			st.push(input[i]);
		}
		else if (input[i] == ')') {
			if (!st.empty() and st.top() == '(') {
				st.pop();
			}
			else {
				ans = false;
				break;
			}
		}
		else if (input[i] == '}') {
			if (!st.empty() and st.top() == '{') {
				st.pop();
			}
			else {
				ans = false;
				break;
			}
		}
		else if (input[i] == ']') {
			if (!st.empty() and st.top() == '[') {
				st.pop();
			}
			else {
				ans = false;
				break;
			}
		}
	}
	if (!st.empty()) {
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
#include<bits/stdc++.h>
using namespace std;


int prefixEvaluation(string s) {
	stack<int>st;
	// In prefix evaluation we always start from right to left
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] >= '0' && s[i] <= '9') {
			st.push(s[i] - '0');
			// we are subtracting '0' becoz it is in asci we want to convert it to integer value
		}
		else {
			int op1 = st.top();
			st.pop();
			int op2 = st.top();
			st.pop();

			switch (s[i]) {
			case '+':
				st.push(op1 + op2);
				break;
			case '-':
				st.push(op1 - op2);
				break;
			case '*':
				st.push(op1 * op2);
				break;
			case '/':
				st.push(op1 / op2);
				break;
			case '^':
				st.push(pow(op1, op2));
				break;

			}
		}
	}
	return st.top();
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << prefixEvaluation("-+7*45+20");

	return 0;

}
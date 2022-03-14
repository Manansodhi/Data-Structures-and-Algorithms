#include<bits/stdc++.h>
using namespace std;


int postfixEvaluation(string s) {
	stack<int>st;
	// In postfix evaluation we always start from left to right
	for (int i =  0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			st.push(s[i] - '0');
			// we are subtracting '0' becoz it is in asci we want to convert it to integer value
		}
		else {
			int op2 = st.top();
			st.pop();
			int op1 = st.top();
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

	cout << postfixEvaluation("46+2/5*7+");

	return 0;

}
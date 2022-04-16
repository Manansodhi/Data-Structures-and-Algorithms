#include<bits/stdc++.h>
using namespace std;


// bool isBalanced(string input) {
// 	stack<char> st;
// 	for (auto ch : input) {
// 		switch (ch) {
// 		case '(':
// 		case '{':
// 		case '[': st.push(ch);
// 			break;
// 		case ')':
// 			if (!st.empty() and st.top() == '(') {
// 				st.pop();
// 			}
// 			else {
// 				return false;
// 			}
// 			break;
// 		case '}':
// 			if (!st.empty() and st.top() == '{') {
// 				st.pop();
// 			}
// 			else {
// 				return false;
// 			}
// 			break;
// 		case ']':
// 			if (!st.empty() and st.top() == '[') {
// 				st.pop();
// 			}
// 			else {
// 				return false;
// 			}
// 			break;
// 		default: continue;
// 		}
// 	}

// 	if (st.empty()) {
// 		return true;
// 	}
// 	return false;
// }


int longeestValidParantheses(string s){
	stack<int>st;
	st.push(-1);
	int max_length=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='('){
			st.push(i);
		}
		else{
			st.pop();
			if(st.empty()){
				st.push(i);
			}
			else{
				max_length=max(max_length,i-st.top());
			}
		}
	}
	return max_length;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	// string s = "{a+(b+c)+([d+e]*f))}+k+((a+b+c)+[d])";
	// //{a+(b+c)+([d+e]*f))}+k

	// if (isBalanced(s)) {
	// 	cout << "Balanced!" << endl;
	// }
	// else {
	// 	cout << "Not Balanced!" << endl;
	// }

	string s = "())";
	
	cout << longeestValidParantheses(s) << endl;

	return 0;

}






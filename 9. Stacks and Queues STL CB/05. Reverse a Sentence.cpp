#include<bits/stdc++.h>
using namespace std;


void reverseString(string s) {
	stack<string> st;
	for (int i = 0; i < s.length(); i++) {
		string word = "";
		while (s[i] != ' ' && i < s.length()) {
			word += s[i];
			i++;
		}
		st.push(word);
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s = "hey , how are you doing?";
	reverseString(s);






	return 0;

}
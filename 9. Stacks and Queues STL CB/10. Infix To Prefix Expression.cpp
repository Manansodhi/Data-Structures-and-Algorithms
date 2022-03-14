#include<bits/stdc++.h>
using namespace std;

int precedence(char c){
	if(c=='^')
		return 3;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else
		return -1;
	//for Opening bracket
}


string infixToprefix(string s){
	stack<char>st;
	string res;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.length();i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			res+=s[i];
		}
		else if(s[i]==')'){
			st.push(s[i]);
		}
		else if(s[i] == '('){
			while(!st.empty() && st.top()!=')'){
				res+=st.top();
				st.pop();
			}
			//for remaining opening bracket
			if(!st.empty()){
				st.pop();
			} 
		}
		else{
			while(!st.empty() && precedence(st.top())>precedence(s[i])){
				res+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout <<infixToprefix("(a-b/c)*(a/k-l)") ;
	cout<<endl;

	return 0;

}
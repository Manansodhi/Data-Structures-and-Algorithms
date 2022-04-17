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


// int longeestValidParantheses(string s){
// 	stack<int>st;
// 	st.push(-1);
// 	int max_length=0;
// 	for(int i=0;i<s.length();i++){
// 		if(s[i]=='('){
// 			st.push(i);
// 		}
// 		else{
// 			st.pop();
// 			if(st.empty()){
// 				st.push(i);
// 			}
// 			else{
// 				max_length=max(max_length,i-st.top());
// 			}
// 		}
// 	}
// 	return max_length;
// }


string SimplifyPath(string path){
	istringstream iss(path);

	vector<string> tokens;
	string token;
	while(getline(iss, token, '/')){
		if(token =="." or token==""){
			continue;
		}
		tokens.push_back(token);
	}

	vector<string> stack;
	if(path[0]=='/'){
		stack.push_back("");
	}

	for(string token:tokens){
		if(token == ".."){
			if(stack.size()==0 or stack[stack.size()-1]==".."){
				stack.push_back("..");
			}
			else if(stack[stack.size()-1] != ""){
				stack.pop_back();
			}
		}
		else{
			stack.push_back(token);
		}
	}

	//corner case when we have only single element
	if(stack.size()==1 and stack[0]==""){
		return "/";
	}

	ostringstream oss;
	int i=0;
	for(auto token:stack){
		if(i!=0){
			oss<< "/";
		}i++;
		oss<<token;
	}

	return oss.str();

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

	// string s = "())";
	
	// cout << longeestValidParantheses(s) << endl;


	// queue<char>q;
	// int freq[27] = {0};

	// char ch;
	// cin>>ch;

	// while(ch!= '.'){
	// 	//reading stream of character untill "."
	// 	q.push(ch);
	// 	freq[ch-'a']++; 
	// 	//storing frequency of each alphabet at its same position in english language like c-a=2 so freq of c will be 
	// 	//stored at 2nd index by incrementing each time

	// 	//query -> Now removing all chars from front of queue which have frequency greater than 1

	// 	while(!q.empty()){
	// 		int idx=q.front()-'a';  
	// 		//finding index of alphabet by subtracting from 'a' to check the freq of that character
	// 		if(freq[idx]>1){
	// 			q.pop();
	// 		}
	// 		else{
	// 			cout<<q.front()<<endl;
	// 			break;
	// 		}
	// 	}
	// 	if(q.empty()){
	// 		cout<<"-1"<<endl;
	// 	}
	// 	cin>>ch;//reading next character
	// }//end of while loop

    string path = "/../x/y/../z/././w/a///../../c/./";

    cout << SimplifyPath(path) << endl;

	return 0;

}






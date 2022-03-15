#include<iostream>
#include"stack.h"
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Stack<int> s;
	s.push(1);
	s.push(12);
	s.push(31);
	s.push(14);
	s.push(5);
	cout<<s.empty()<<endl;
	cout<<s.getsize()<<endl;
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();s.pop();s.pop();s.pop();
	cout<<s.top()<<endl;


	return 0;

}
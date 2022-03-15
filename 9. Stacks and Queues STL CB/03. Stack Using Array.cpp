#include<bits/stdc++.h>
using namespace std;


template<typename T>

class Stack {
	T * arr;
	int top;
	int capacity;
public:
	Stack() {
		arr = new T[4];
		top=-1;
		capacity=4;
	}

	void push(T x){
		// if(top == capacity){
		// 	cout<<"stack overflow"<<endl;
		// 	return;
		// }
		//if array is full we double the size of array and copy the elements in new array
		T * newarr ;
		newarr= new T[2*capacity];
		for(int i=0;i<capacity;i++){
			newarr[i]=arr[i];
		}
		capacity *= 2;
		delete[]arr;
		arr=newarr;
		top++;
		arr[top]=x;
	}

	void pop(){
		if(top==-1){
			cout<<"No elements to pop"<<endl;
			return;
		}
		top--;
	}

	T TOP_element(){
		if(top==-1){
			cout<<"No element in stack" <<endl;
			return -1;
		}
		return arr[top];
	}

	int size(){
		if(top==-1){
			return 0;
		}
		return top;
	}

	bool empty(){
		return top==-1;
	}

};


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
	cout<<s.size()<<endl;
	cout<<s.TOP_element()<<endl;
	s.pop();
	cout<<s.TOP_element()<<endl;
	s.pop();
	cout<<s.TOP_element()<<endl;
	s.pop();s.pop();s.pop();s.pop();
	cout<<s.TOP_element()<<endl;
	

	return 0;

}
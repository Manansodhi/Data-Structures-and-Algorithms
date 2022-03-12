#include<iostream>
#include<queue.h>
using namespace std;


template<typename T>
class Stack {
	queue<T> q1, q2; // 2 objects of queue. q1 is non-empty and q2 is empty queue

	public:
	void push(T x){
		q1.push(x);
	} 

	void pop(){
		//pop from stack means -> remove the last element from q1(which is pushedlast in stack/queue q1).
		//for this we have to move first n-1 elements in q2 from q1 and last element is the popped element
		//after copying first n-1 elements in q2. now q1 will be empty so we interchange there name (swap(q1,q2))
		//after interchanging there name now q1 is non-empty and q2 is empty queue

		//Base condition
		if(q1.empty()){
			return;
		}   

		// copying n-1 elements of q1 to q
		while(q1.size() > 1){
			T element = q1.front();
			q2.push(element);
			q1.pop();
		}
		q1.pop(); //Removes last elementfrom q1 that we wanted to pop from stack

		//Swap the names of q1 and q2 OR swap(q1,q2)
		queue<int> temp = q1;
		q1 = q2;
		q2 = temp;
	}


	T top(){
		while(q1.size()>1){
			T element = q1.front();
			q2.push(elemenet);
			q1.pop();
		}

		//first element in q1
		T element = q1.front();
		q1.pop();
		q2.push(element);
		swap(q1,q2);
		return element;
	}

	int size(){
		return q1.size() + q2.size();
	}

	bool empty(){
		return size() == 0;
	}
};




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Stack<int>s;
	s.push(1);
	s.push(2);
	s.push(3);

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}


	return 0;

}
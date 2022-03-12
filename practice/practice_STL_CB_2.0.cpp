#include<bits/stdc++.h>
using namespace std;

/*
LIST :- underlying data structure is doubly linked list so movement in both direction is possible and push nad pop from both front and
back is possible in only O(1) time we can also insert and erase element from any position becouse it only has connect the node in between
by taking perivious and next element address
whereas in FORWARD LIST :- it has underlying data structure as singly linked list which can move in forward dirction only and it only
stores the address of its next node. FORWARD_LIST performs better than array, vector, deque in INSERTING, EXTRACTING AND MOVING elements
in any position with in the container
DRAWBACK :- direct access not possible
*/


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
			q2.push(element);
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


	// list <int> l;
	// list <int>l1 {1, 2, 3, 4, 5, 6};
	// list<string>l2 {"apple", "guava", "mango", "bananna"};

	// l2.push_back("pineapple");

	// for (auto s : l2) {
	// 	cout << s << "-->";
	// }
	// cout << endl;

	// l2.sort();
	// cout << "Sorted" << endl;
	// for (auto s : l2) {
	// 	cout << s << "-->";
	// }
	// cout << endl;

	// l2.reverse();
	// cout << "reversed" << endl;
	// for (auto s : l2) {
	// 	cout << s << "-->";
	// }
	// cout << endl;

	// cout << "Front element : " << l2.front() << endl;
	// l2.pop_front();
	// cout << "After Popping front element" << endl;
	// for (auto s : l2) {
	// 	cout << s << "-->";
	// }
	// cout << endl;

	// cout << "Pushing at front" << endl;
	// l2.push_front("kiwi");
	// //iterating thru iterator
	// for (list<string>::iterator it = l2.begin(); it != l2.end(); it++) {
	// 	cout << (*it) << "-->";
	// }
	// cout << endl;

	// cout<<"Adding some fruits at the end"<<endl;
	// l2.push_back("orange");
	// l2.push_back("lemon");
	// for (auto s : l2) {
	// 	cout << s << "-->";
	// }
	// cout << endl;


	// cout << "Removing fruit by value" << endl;
	// /*if list have same multiple element and we remove one element then all the occurence of that element will be removed from list */
	// string f;
	// cin >> f;
	// l2.remove(f);
	// for (auto s:l2){
	// 	cout<<s<<"-->";
	// }
	// cout<<endl;


	// cout<<"Erasing one or more elements from list"<<endl;
	// /*as we know that list has internally implemented as doubly linked list and that doesnot have continous memory allocation for its
	//  each node so direct access of element from list is not allowed so we cannot this to remove element from list
	//  auto it = l2.begin()+3;  we can not go to 3rd element from begin by doing l2.begin()+3 becoz of its non-continous memory
	//  l2.erase(it);
	// */

	// auto it1 = l2.begin();
	// it1++;
	// it1++;
	// l2.erase(it1);
	// for (auto s:l2){
	// 	cout<<s<<"-->";
	// }
	// cout<<endl;


	// cout <<"Inserting elements in the list at any position" << endl;
	// auto it3 = l2.begin();
	// it3++;
	// l2.insert(it3,"fruit juice");
	// for (auto s:l2){
	// 	cout<<s<<"-->";
	// }
	// cout<<endl;


	// list<pair<int,int> >*l; //dynamic list (to get input from user for number of vertexes and we have to create array of linked list)
	// int n; //No of vertices
	// cin>>n;
	// l = new list<pair<int,int> > [n]; //creating a new array depending on number of vertices inputed to store connection between edge and its distence(weight) from that

	// int e; //No of edges
	// cin>>e;
	// //loop for taking input of edges(connection) between vertexes and its corresponding weight(distance)
	// for(int i =0;i<e;i++){
	// 	int x,y,wt;
	// 	cin>>x>>y>>wt;

	// 	l[x].push_back(make_pair(y,wt)); // forward egde (uni-directional)
	// 	l[y].push_back(make_pair(x,wt)); // reverse egde (bi-directinal)

	// }

	// //printing linked list
	// for(int i=0;i<=n;i++){
	// 	cout<<"linked list " << i <<"-->";
	// 	//every element of linked list is going to be pair of 2nd edge and distance between them
	// 	for(auto xp:l[i]){
	// 		cout <<"("<<xp.first<<", "<<xp.second <<"), ";
	// 	}
	// 	cout<<endl;
	// }


	// stack<int> s;
	// for(int i=0;i<5;i++){
	// 	s.push(i); //O(1) time
	// }

	// while(!s.empty()){
	// 	cout<<s.top()<<", ";  //O(1) time
	// 	s.pop();  //O(1) time
	// }
	// cout<<endl;

	// queue<int> q;
	// for(int i=0;i<5;i++){
	// 	q.push(i); //O(1) time
	// }

	// while(!q.empty()){
	// 	cout<<q.front()<<", ";  //O(1) time
	// 	q.pop();  //O(1) time
	// }
	// cout<<endl;


	Stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}




	return 0;

}
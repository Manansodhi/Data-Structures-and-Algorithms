#include<bits/stdc++.h>
using namespace std;


// //search Number for interger data type only
// int search(int arr[],int n,int key ){
// 	for(int p=0;p<n;p++){
// 		if(arr[p]==key){
// 			return p;
// 		}
// 	}
// 	return -1;
// }

////template
// //search Number any genric data type
// // template<class T>  OR
// template<typename T>
// int search(T arr[],int n,T key ){
// 	for(int p=0;p<n;p++){
// 		if(arr[p]==key){
// 			return p;
// 		}
// 	}
// 	return -1;
// }


// //template + iterator
// template<class forwarditerator, class T>
// forwarditerator search(forwardIterator start, forwardIterator end, T key){
// 	while(start!=end){
// 		if(*start == key){
// 			return start;
// 		}
// 		start++;
// 	}
// 	return -1;
// }


//template + iterator + Camparator
class Book {
public:
	string name;
	int price;

	Book() {

	}

	Book(string name, int price) {
		this->name = name;
		this->price = price;
	}
};

template<class forwardIterator, class T, class Compare>
forwardIterator search(forwardIterator start, forwardIterator end, T key, Compare cmp){
	while(start != end){
		if(cmp(*start,key)){
			return start;
		}
		start++;
	}
	return end;
}

class BookCampare{
public:
	bool operator()(Book A, Book B){
		if(A.name == B.name){
			return true;
		}
		return false;
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int arr[]={1,2,3,4,5,7,9};
	// int key =5;
	// int n = sizeof(arr)/sizeof(int);
	// cout<<search(arr,n,key)<<endl;

	// float b[]={1.1,1.2,1.3};
	// float k=1.3;
	// cout<<search(b,n,k)<<endl;


	// list<int>l;
	// l.push_back(1);
	// l.push_back(2);
	// l.push_back(4);
	// l.push_back(8);
	// l.push_back(9);

	// auto it = search(l.begin(),l.end(),5);
	// if(it==l.end()){
	// 	cout<<"Not present";
	// }
	// else{
	// 	cout<<*it<<endl;
	// }

	Book b1("C++",100);
	Book b2("Java",200);
	Book b3("Python",300);

	list<Book>l;
	l.push_back(b1);
	l.push_back(b2);
	l.push_back(b3);

	Book booktofind("C++",150);
	BookCampare cmp;
	auto it = search(l.begin(),l.end(),booktofind,cmp);
	if(it!=l.end()){
		cout<<"Bookk Found in libaray"<<endl;
	}
	else{
		cout<<"Book Not found in libaray"<< endl;
	}


	return 0;
}
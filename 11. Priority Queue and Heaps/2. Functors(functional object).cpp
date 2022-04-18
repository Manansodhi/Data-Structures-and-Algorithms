#include<bits/stdc++.h>
using namespace std;

class fun {
public:
	void operator()() {
		cout << "Having fun inside operator() fun!" << endl;
	}
	void operator()(string s) {
		cout << "Having fun inside operator() fun! with " << s << endl;
	}
};

int main() {
	fun f; // f is the object of fun class (constructor call)
	f();   //overloaded() operator looks like function call with class object f.
	//f is an object but behaves like function call so f is called functors(functional object)
	f("C++");
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

class person {
public:
	string name;
	int age;
	person() {

	}
	person(string n, int a) {
		name = n;
		age = a;
	}
};

class personCompare {
public:
	bool operator()(person A, person B) {
		cout << "Comparing" << A.age << "with" << B.age << endl;
		return A.age < B.age;
	}
};

int main() {
	int n;
	cin >> n;
	priority_queue<person, vector<person>, personCompare>pq;
	for (int i = 0; i < n; i++) {
		string name;
		int age;
		cin >> name >> age;
		person p(name, age);
		pq.push(p);
	}
	int k = 3;
	for (int i = 0; i < k; i++) {
		person p = pq.top();
		cout << p.name << " " << p.age << endl;
		pq.pop();
	}

	return 0;
}
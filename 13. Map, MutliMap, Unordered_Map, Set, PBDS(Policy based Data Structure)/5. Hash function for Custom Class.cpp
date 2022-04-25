#include<bits/stdc++.h>
using namespace std;


/*
hashmap<student,int> h;
student->custom class as a key
1. Define own hash function
2. in this student class have to oveload "==" becoz when we are travesing the linked list inside the
 hashmap and when we give a key or multiple same key (same name) but will have different roll number

*/
class student {
public:
	string firstname, lastname, rollno;
	student(string f, string l, string rNO) {
		firstname = f;
		lastname = l;
		rollno = rNO;
	}

	bool operator == (const student&s)const {
		return rollno == s.rollno ? true : false;
	}
};

//size_t -> unsigned int type of datatype used to represent size of some memory in byte

class HashFN {
public:
	size_t operator()(const student&s)const {
		return s.firstname.length() + s.lastname.length();
	}
};


int main() {
	unordered_map<student, int, HashFN> student_map;
	student s1("MANAN", "SODHI", "3044");
	student s2("NANAN", "Singh", "3045");
	student s3("AMAN", "SOI", "3040");
	student s1("kl", "sharma", "3041");

	student_map[s1] = 100;
	student_map[s2] = 120;
	student_map[s3] = 45;
	student_map[s4] = 26;

	//iterate over all students
	for (auto s : student_map) {
		cout <<< s.first.firstname << " " << s.fisrt.rollno << " Marks " << s.second << endl;
	}

}
/*
Tell the positions

In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design 
& Analysis and Operating Systems. Marks for each subject of all the students are provided to you. You have to tell 
the position of each student in the class. Print the names of each student according to their position in class. 
Tie is broken on the basis of their roll numbers. Between two students having same marks, the one with less roll 
number will have higher rank. The input is provided in order of roll number.

Input Format:
First line will have a single integer ‘n’, denoting the number of students in the class.Next ‘n’ lines each will 
have one string denoting the name of student and three space separated integers m1, m2, m3 denoting the marks in 
three subjects.

Output Format:
Print ‘n’ lines having two values: First, the position of student in the class and second his name.

Constraints:
1 <= n <= 10^5
0 <= m1, m2, m3 <= 100

Sample Input:
3
Mohit 94 85 97
Shubham 93 91 94
Rishabh 95 81 99

Sample Output:
1 Shubham
2 Mohit
3 Rishabh

*/

#include<bits/stdc++.h>
using namespace std;


class student{
public:
	string name;
	int marks;
	int roll;
};


bool myCompare(student a,student b){
	if(a.marks!= b.marks){
		return (a.marks>b.marks);
	}
	else{
		return (a.roll <b.roll);
	}
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    int n;
    cin>>n;
    vector<student>stud;
    for(int i =0;i<n;i++){
    	string temp_name;
    	int sub1Marks,sub2Marks,sub3Marks;
    	cin>>temp_name>>sub1Marks>>sub2Marks>>sub2Marks;
    	int sum = sub1Marks+sub2Marks+sub3Marks;
    	student temp_stud;
    	temp_stud.name=temp_name;
    	temp_stud.marks = sum;
    	temp_stud.roll=i+1;

    	student.push_back(temp_stud);
    }
    sort(stud.begin(),stud.end(),myCompare);
    for(int i =0;i<n;i++){
    	cout <<i+1<<" "<<stud.at(i).name<<endl;
    }
    return 0;
}
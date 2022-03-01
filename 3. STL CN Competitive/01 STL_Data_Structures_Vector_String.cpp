#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;



int main(){

	//Vector
	vector<int> v;

	for(int i=0;i<5;i++){
		v.push_back(i+1);
	}
	vector<int>::iterator it;

	for(it=v.begin();it!=v.end();it++){
		cout<<*it<<endl;
	}


	//String
	string s = "Parikh";
	string s1(s,2,4);
	cout<<s<<endl;
	cout<<s1<<endl;

	string s2 = s.substr(2,4);
	cout<<s2<<endl;

	if(s1.compare(s2) == 0){
		cout<<s1 <<"is equal to " << s2<<endl;
	}else{
		cout<<s1 <<"is not equal to " << s2<<endl;
	}

   
	return 0;
}
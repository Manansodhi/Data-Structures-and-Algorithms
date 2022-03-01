#include<bits/stdc++.h>
using namespace std;


bool compare (string a, string b){
	//if 2 strings are equal in length then sort in lexixographic order (means string of greater length will come 
	//at top and between equal length strings one smaller in lexicographic order will come first ) 
	if(a.length() == b.length()){
		return a<b;
		//overloading "<" to compare strings based on lexicographic order
	}
return a.length() < b.length();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;
	cin.get();
	string s[100];

	for(int i=0;i<n;i++){
		getline(cin,s[i]);
	}
	//n -> number of string
	//sort(s,s+n);
	sort(s,s+n,compare);

	for(int i =0;i<n;i++){
		cout<<s[i]<<endl;
	}
return 0;
}
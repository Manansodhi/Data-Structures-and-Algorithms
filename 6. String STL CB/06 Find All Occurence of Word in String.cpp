#include<bits/stdc++.h>
using namespace std;

vector<int>stringSearch(string s, string word){
	vector<int>result;
	int index = s.find(word);
	while(index != -1){
		result.push_back(index);
		index = s.find(word,index+1);
	}
	return result;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	getline(cin,s);
	string word;
	getline(cin,word);
	vector<int> ans = stringSearch(s,word);
	for(auto v:ans){
		cout << v<<",";
	}
	cout<<endl;



	return 0;
}
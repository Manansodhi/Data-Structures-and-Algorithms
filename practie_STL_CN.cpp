#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<unordered_map>
#include<bits/stdc++.h>
#include <sstream>
typedef long long ll;
using namespace std;

// char getChar(int i) {
// 	return (char)(i + 97);
// }

// void printPalindromicString(string s) {
// 	map<char, vector<int> > indexesMap;
// 	for (int i = 0; i < s.length(); i++) {
// 		indexesMap[s[i]].push_back(i + 1);
// 	}

// 	int odd_count_freq = 0;
// 	for (int i = 0; i < 26; i++) {
// 		if ((indexesMap[getChar(i)].size()) % 2 != 0) {
// 			odd_count_freq++;
// 		}
// 	}

// 	if (odd_count_freq >= 2) {
// 		cout << "-1";
// 		return;
// 	}

// 	int ans[s.length()];
// 	int start = 0, end = s.length() - 1;
// 	for (int i = 0; i < 26; i++) {
// 		char curr_char = getChar(i);
// 		for (int j = 0; j < indexesMap[curr_char].size(); j += 2) {
// 			if ((indexesMap[curr_char].size() - j) == 1) {
// 				ans[s.length() / 2] = indexesMap[curr_char][j];
// 				continue;
// 			}
// 			ans[start] = indexesMap[curr_char][j];
// 			ans[end] = indexesMap[curr_char][j + 1];
// 			start++;
// 			end--;
// 		}
// 	}

// 	for (int i = 0; i < s.length(); i++) {
// 		cout << ans[i] << " ";
// 	}
// }


//Count no of words in string
int countWords(string str) {
	//breaking input into word using stringStream
	stringstream s(str); // Used for breaking words
	string word; //to store indivdual words
	int count = 0 ;
	while (s >> word) {
		// s >> word -> reading string(word) from stringstream object(s)
		count++;
		//cout<<count<<endl;
	}
	return count;
}


void PrintFrequency(string str){
	//each word is mapped to its frequency
	map<string,int> freq;
	stringstream ss(str); // ss -> object of stringstream str -> input string
	string words;
	while(ss>>words){
		//Extracting word by word from stream object ss into words(string) till end
		freq[words]++;
	}
	for(auto i:freq){
		cout<<i.first <<":"<<i.second<<endl;
	}
}


string removeSpace(string str)
{
	stringstream ss;
	string temp;

	// Storing the whole string into string stream
	ss << str;

	// Making the string empty
	str = "";

	// Running loop till end of stream
	while (!ss.eof()) {

		// Extracting word by word from stream
		ss >> temp;

		// Concatenating in the string to be returned
		str = str + temp;
	}
	return str;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
// 	//Pair

// 	pair<int, char> p;
// 	p = make_pair(2, 'b');
// 	pair<int, char> p2(1, 'a');
// 	cout << p.fi " << p2.second << endl;
// rst << " " << p.second << endl;
// 	cout << p2.first << "

// 	//Set

// 	set<int> s;
// 	int arr[] = {1, 2, 3, 4, 5, 6, 5};

// 	for (int i = 0; i < 7; i++) {
// 		s.insert(arr[i]);
// 	}

// 	set<int>::iterator it;

// 	for (it = s.begin(); it != s.end(); it++) {
// 		cout << *it << endl;
// 	}

// 	if (s.find(7) == s.end()) {
// 		cout << "Element not found" << endl;
// 	} else {
// 		cout << "Element found" << endl;
// 	}


	// // Map

	// int arr[] = {1, 2, 3, 4, 5, 6, 5};
	// unordered_map<int, int> m;

	// for (int i = 0; i < 7; i++) {
	// 	m[arr[i]] = m[arr[i]] + 1;
	// }

	// unordered_map<int, int>::iterator it;
	// for (it = m.begin(); it != m.end(); it++) {
	// 	cout << it->first << " :" << it->second << endl;
	// }
	// cout << endl;
	// m.erase(1);
	// for (it = m.begin(); it != m.end(); it++) {
	// 	cout << it->first << " :" << it->second << endl;
	// }

// //HUSSIAN SET

// 	int n, m;
// 	cin >> n >> m;
// 	ll arr[n];
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 	}
// 	sort(arr, arr + n);
// 	int count_m = 0, end_p = n - 1;
// 	queue< ll > q;

// 	while (m--) {
// 		int curr_m;
// 		cin >> curr_m;
// 		ll ans;
// 		for (; count_m < curr_m; count_m++) {
// 			if(end_p>=0 &&(q.empty() ||(arr[end_p]>=q.front()))){
// 				ans=arr[end_p];
// 				end_p--;
// 			}
// 			else{
// 				ans=q.front();
// 				q.pop();
// 			}
// 			q.push(ans/2);
// 		}
// 		cout<<ans <<endl;
// 	}


// //PERMUTATION & PALINDROMIC STRING
// 	string s;
// 	cin >> s;
// 	printPalindromicString(s);
// 	cout << endl;


	string s ;
	// cin >> s; wiil not worl becoz will not take input after space
	getline(cin,s);
	//cout << countWords(s) << endl;
	//PrintFrequency(s);
	cout<<removeSpace(s)<<endl;

	return 0;
}
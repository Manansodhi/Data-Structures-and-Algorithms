#include <bits/stdc++.h>
using namespace std;

	struct interval{
		int st;
		int et;
	};

	bool compare(interval i1, interval i2){
		return i1.st < i2.st;
	}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	// int t;
	// cin >> t;
	// while (t--){
	// 	int n;
	// 	cin >> n ;
	// 	int * arr = new int [n];
	// 	for (int i = 0; i < n; i++){
	// 		cin >> arr[i];
	// 	}
	// }


    // VECTOR

	// vector<int> v;
	// vector <int> :: iterator it;
	// int j = 1;

	// for (int i = 0; i < v.size(); i++){
	// 	v[i] = j++;
	// }

	// for (int i = 0; i < 5; i++){
	// 	v.push_back(i+1);
	// }

	// for (it = v.begin(); it != v.end(); it++){
	// 	cout << *it << endl;
	// }


	//STRING

	// string s = "manan";
	// cout << s << endl;
	// // string s1(s);
	// // cout << s1 << endl;

	// string s1(s, 2, 4);
	// cout << s1 << endl;

	// string s2 = s.substr(1, 4);
	// cout << s2 << endl;

	// if (s1.compare(s2) == 0){
	// 	cout << s1 << "is equal" << s2 << endl;
	// }
	// else{
	// 	cout << s1 << " is not equal " << s2 << endl;
	// }


	//PAIR

	// pair <int, char> p ;
	// pair <int, char> p2(1, 'a');
	// cout << p2.first << " " << p2.second << endl;
	// p = make_pair(2, 'b');
	// cout << p.first <<" " << p.second << endl;


	// SET   contains all unique values and print them in sorted order
	// set doesnot have index so we can not use loop here to print its value we have to use iterator
	// unordered_set -> contains unique elements, implemented using hashing , elements are in 
	// sorted order, Random Access not possible INSERTION & DELETION :O(1)-> Avg case | O(N) ->Worse case



	// set<int> s;
	// int arr[] = {1,4,5,6,3,2};
	// for (int i = 0; i < 6; i++){
	// 	s.insert(arr[i]);
	// }
	// set<int> :: iterator it;
	// for (it = s.begin(); it != s.end(); it++){
	// 	cout << *it <<" ";
	// }
	// cout << endl;
	// if (s.find(6) == s.end()){ //s.find(6) -> returns an iterator
	// 	cout << "Element not found" << endl;
	// }
	// else{
	// 	cout << "Elements found" << endl;
	// }

	//MAP -> Also stores the frequency corresponding to that element
	// map uses Balanced Binary Search Tree take log n time in searching, finding,
	// deleting and inserting made from Balanced BST and unordered_map made thru HASH TABLE 
	// O(1) in avg case O(N) in worse case for inserting, deleting, finding in unordered_map 

	// Map and unorderd_map output will be same but the order will be different
	// int arr[] = {1,3,2,3,4,5,7,3,2,1};
	// map <int, int> m;

	// for (int i = 0; i < 10; i++){
	// 	m[arr[i]]++;
	// }

	// map <int, int> :: iterator it;
	// // for (it = m.begin(); it != m.end(); it++){
	// // 	cout << it->first << ":" << it->second << endl;
	// // }

	// m.erase(2); // it will erase all 2 in a map
	// for (it = m.begin(); it != m.end(); it++){
	// 	cout << it->first << ":" << it->second << endl;
	// }

	// int arr[] = {1,2,3,4,5,6,5};
	// unordered_map<int,int> m;

	// for(int i=0;i<7;i++){
	// 	m[arr[i]] = m[arr[i]]+1;
	// }

	// unordered_map<int,int>::iterator it;
	// for(it=m.begin();it!=m.end();it++){
	// 	cout<<it->first << " :" << it->second<<endl;
	// }
	// cout<<endl;
	// m.erase(1);
	// for(it=m.begin();it!=m.end();it++){
	// 	cout<<it->first << " :" << it->second<<endl;
	// }


	// STL FUNCTIONS

	// int arr[] = {9,3,2,4,5,7};
	// sort(arr, arr+6, greater<int>());
	// for(int i = 0; i < 6; i++){
	// 	cout << arr[i] << " ";
	// }

	// we have start and finish time of interval and we want to sort according either 
	// start or finish time only so for this we have to make compartor function

	// interval arr[] = {{6,4},{3,4},{4,6},{8,13}};
	// sort(arr, arr + 4, compare);
	// for (int i = 0; i < 4; i++){
	// 	cout << arr[i].st << ":" << arr[i].et << endl;
	// }

	//Binary Search always applied on increasingly sorted array

	int arr[] = {2,1,4,3,1,7,8,9};
	sort(arr, arr + 8);
	for (int i = 0; i < 8; i++){
		cout << arr[i] <<" ";
	}
	cout << endl;
	cout << binary_search(arr, arr + 6, 3) << endl;
	cout << binary_search(arr, arr + 6, 8) << endl;

	cout << lower_bound(arr, arr + 8 , 2) << endl; // for finding index of number it will return pointer 
	cout << lower_bound(arr, arr + 8 , 2) - arr << endl; // this will return index of that number
	cout << lower_bound(arr, arr + 8 , 5) - arr << endl; // whem we want to find the index of number which is not in array then lower_bound() will return index of number greater than searched index
	cout << lower_bound(arr, arr + 8 , 1) - arr << endl; // when want to find the index of number which has 2 occurence then it will return the index of 1rst occurence of that number
	

	//lower_bound() m kya hota h ki agar number nahi h jiska index chahiye hame toh voh us number ka index return karta h jo us number se just bada ho .
	//upper_bound() m kya hota h ki jis number ka index chahiye h hame toh voh har bar apne se just bade number ka index return karta h

	cout << upper_bound(arr, arr + 8 , 3) - arr << endl;
	cout << upper_bound(arr, arr + 8 , 1) - arr << endl;
	// repative upper_bound() case m jo number bade m ata h usse just bade number ka index return karta h
	

	cout << __gcd(10, 6) << endl;
	cout << pow(2,5) << endl;
	cout << pow(2.2, 5) << endl;

	return 0;
}
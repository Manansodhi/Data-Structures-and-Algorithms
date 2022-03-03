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
// class Book {
// public:
// 	string name;
// 	int price;

// 	Book() {

// 	}

// 	Book(string name, int price) {
// 		this->name = name;
// 		this->price = price;
// 	}
// };

// template<class forwardIterator, class T, class Compare>
// forwardIterator search(forwardIterator start, forwardIterator end, T key, Compare cmp){
// 	while(start != end){
// 		if(cmp(*start,key)){
// 			return start;
// 		}
// 		start++;
// 	}
// 	return end;
// }

// class BookCampare{
// public:
// 	bool operator()(Book A, Book B){
// 		if(A.name == B.name){
// 			return true;
// 		}
// 		return false;
// 	}
// };


// bool compare(int a, int b) {
//     return a < b;
// }

// void bubble_sort(int a[], int n, bool(&cmp)(int a, int b)) {

//     //put n-1 large elements to the end
//     for (int itr = 1; itr <= n - 1; itr++) {

//         //pairwise swapping int the unsorted array
//         for (int j = 0; j <= (n - itr - 1); j++) {
//             if (cmp(a[j], a[j + 1])) {
//                 swap(a[j], a[j + 1]);
//             }
//         }
//     }
// }


// bool compare(int a, int b) {
//     return a <= b;
// }


// bool comp(string s1, string s2)
// {
//     if(s1.length() < s2.length())
//         return 1;
//     else if(s1.length() > s2.length())
//         return 0;
//     else return s1 < s2;
// }


// vector<int> nextPermutation(vector<int>&nums){
// 	int n = nums.size();
// 	if(n==1){
// 		return nums;
// 	}
// 	int index1;
// 	for(int i = n-2;i>=0;i--){
// 		if(nums[i]<nums[i+1]){
// 			index1 = i;
// 			break;
// 		}
// 		int index2=0;
// 		if(index1<0){
// 			reverse(nums.begin(),nums.end());
// 		}
// 		else{
// 			for(int i = n-1;i>=0;i--){
// 				if(nums[i]>nums[index1]){
// 					index2=i;
// 					break;
// 				}
// 			}
// 		}
// 		swap(nums[index1],nums[index2]);
// 		reverse(nums.begin()+index1+1,nums.end());
// 	}
// 	return nums;
// }


// bool compare(pair<int, int> a, pair<int, int> b) {
// 	return a.second < b.second;
// }

// bool compare (string a, string b){
// 	//if 2 strings are equal in length then sort in lexixographic order (means string of greater length will
// come at top and between equal length strings one smaller in lexicographic order will come first )
// 	if(a.length() == b.length()){
// 		return a<b;
// 		//overloading "<" to compare strings based on lexicographic order
// 	}
// return a.length() < b.length();
// }



// //instead we pass array(char*) of delimeter we accept single character that will be delimiter
// char *mystrtok(char*str, char delim) {
// //string str and single char as delimeter

// 	we are making multiple function call to extract token each time for this we have to maintain variable which will maintain
// 	that how much string is tokenized and from where it should give next token for this we have to maintain static variable
// 	(to maintain how many token you have returned till now)
// 	static input pointer. state of static variable is intialized only once in function call and in every subsequent call it will
// 	have same state as in previous function call

// 	static char *input = NULL;


// 	//input will point to the starting position of string if string str is not NULL
// 	if (str != NULL) {
// 		input = str;
// 	}

// 	//Base case. After the final token has been returned
// 	if (input == NULL) {
// 		return NULL;
// 	}


// 	/*
// 	when designing  strtok() we have to store the entire string inside function and for storing we will take dynamic array
// 	becoz it will exist even after function call is over. we will create new array of same length of string each time becoz whole
// 	 string may be one token also +1 for null character which we will add for last token
// 	*/

// 	char *output = new char[strlen(input) + 1];
// 	int i = 0;
// 	for (; input[i] != '\0'; i++) {
// 		if (input[i] != delim) {
// 			output[i] = input[i];//copying the string in output array untill delimeter
// 		}
// 		else {
// 			output[i] = '\0';
// 			input = input + i + 1; //to change the location of input pointer after first token is copied in output array
// 			return output;
// 		}
// 	}
// 	/*corner case: For very last token there might may not be space at the end so four loop will get over so we put '\0' at the
// 	 end explicity*/
// 	output[i] = '\0';
// 	input = NULL;
// 	return output;

// }

// void space20(char* s) {
// 	int countSpace = 0, additionalSpace = 0;
// 	for (int itr = 0; s[itr] != '\0'; itr++) {
// 		if (s[itr] == ' ') {
// 			countSpace++;
// 		}
// 	}
// 	additionalSpace = (3 * countSpace) - countSpace;
// 	s[strlen(s) + additionalSpace] = '\0';
// 	for (int itr = strlen(s) - 1 + additionalSpace, j = strlen(s) - 1; j >= 0; j--) {
// 		if (s[j] == ' ') {
// 			s[itr] = '0';
// 			s[itr - 1] = '2';
// 			s[itr - 2] = '%';
// 			itr -= 3;
// 		}
// 		else {
// 			s[itr] = s[j];
// 			itr--;
// 		}
// 	}
// }


bool checkSubsequence(string s1,string s2){
	int m = s1.length(),n=s2.length();
	int j=n;
	for(int i=m;i>=0;i--){
		if(s1[i] == s2[j]){
			j--;
		}
	}
	if(j==-1){
		return true;
	}
	else{
		return false;
	}
}



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

	// Book b1("C++",100);
	// Book b2("Java",200);
	// Book b3("Python",300);

	// list<Book>l;
	// l.push_back(b1);
	// l.push_back(b2);
	// l.push_back(b3);

	// Book booktofind("C++",150);
	// BookCampare cmp;
	// auto it = search(l.begin(),l.end(),booktofind,cmp);
	// if(it!=l.end()){
	// 	cout<<"Bookk Found in libaray"<<endl;
	// }
	// else{
	// 	cout<<"Book Not found in libaray"<< endl;
	// }

	// ALGORITHM
	// int arr[] = {1, 10, 11, 9, 100};
	// int n = sizeof(arr) / sizeof(int);
	// int key = 13;

	// //Find Function
	// // when key is not present in the array find fumc will return the pointer to the last position of array
	// auto it = find(arr, arr + n, key); //find function returns pointer to that location
	// cout << it << endl; // this will return the addres of key

	// //by subracting the starting element address with cyrrent element address we will get the number of
	// //elements between element
	// int index = it - arr;
	// cout << index << endl;
	// if (index == n) {
	//     cout << key << " Not found" << endl;
	// }
	// else {
	//     cout << key << " Present at index " << index << endl;
	// }



	// //BINARY SEACRH  Time :- O(Log N)
	// int arr[] = {20, 30, 40, 40, 40, 50, 100};
	// int n = sizeof(arr) / sizeof(int);
	// int key = 30;
	// bool present = binary_search(arr, arr + n, key); //binary_search() will return either true/false
	// if (present) {
	//     cout << "presemt" << endl;
	// }
	// else {
	//     cout << "absent!" << endl;
	// }


	// //upper_bound()   lower_bound()  function to get index of element
	// int arr[] = {20, 30, 40, 40, 40, 50, 100};
	// int n = sizeof(arr) / sizeof(int);
	// int key = 40;

	// //int * lb becoz lower_bound() will return address
	// // it will return the address of first element >= key
	// auto lb = lower_bound(arr, arr + n, 40);
	// cout << (lb - arr) << endl; //2

	// // it will return the address of first element > key
	// auto ub = upper_bound(arr, arr + n, 40);
	// cout << (ub - arr) << endl; //5

	// //Upper_bound - lower_bound -> gives the frequency of element
	// // if we want to find the frequency of element in sorted array we do that by subtracting ub-lb
	// cout << "occurance frequency of 40 is " << (ub - lb) << endl;

	// // if we want to find the lower_bound of 41 then it will return next greater element then 41 that is 50
	// //and it's index is 5 and upper bound will also be 5 and ub-lb will be zero becoz it is not present in
	// //array


	// int n, key;
//    cin >> n;
//    int a[1000];
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }

//    bubble_sort(a,n,compare);
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    }
//    cout << endl;

//    rotate(a, a + 2, a + n);

//    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    }
//    cout << endl;

//    //When we want to generate next lexiographic bigger number
//    next_permutation(a, a + n);
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    }
//    cout << endl;

//    reverse(a + 2, a + n);


//    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    }
//    cout << endl;


//INDIAN MONEY COIN CHANGE
	// int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
//    int n = sizeof(coins) / sizeof(int);
//    int money = 208;
//    while(money>0){
//    	int lb = lower_bound(coins, coins+n, money, compare)-coins -1;
//    	int m = coins[lb];
//    	money -= m;
//    	cout<<m<<" ";
//    }
//    cout << endl;



// vector< string > data = {"b", "a", "c", "abc", "bca", "xy"};
// sort(data.begin(), data.end(), comp);
// for(string item : data)
//         cout << item << " ";


// int n;
// 	cin>>n;
// 	vector<int>v(n);
// 	int number;
// 	for(int i = 0;i<n;i++){
// 		cin>>number;
// 		v.push_back(number);
// 	}
// 	vector<int> ans=nextPermutation(v);
// 	for(auto i:ans){
// 		cout<<i<<" ";
// 	}
// 	cout<< endl;


// int no, m, n;
// 	cin >> no;
// 	pair<int, int>arr[no];
// 	for (int i = 0; i < i < no; i++) {
// 		cin >> m >> n;
// 		arr[i] = make_pair(m, n);
// 	}

// 	sort(arr, arr + no, compare);

// 	int ans = 1, chosen = 0;
// 	for (int i = 1; i < no; i++) {
// 		if (arr[i].first >= arr[chosen].second) {
// 			ans++;
// 			chosen = i;
// 		}
// 	}
// 	cout << ans << endl;


	// string s0;
	// string s1("Hello");
	// string s2 = "Hello World";
	// string s3(s2);
	// string s4=s3;

	// //styring object from array
	// char a[] = {'a', 'b', 'c','\0'};
	// string s5(a);

	// cout<<s0<<endl;
	// cout<<s1<<endl;
	// cout<<s2<<endl;
	// cout<<s3<<endl;
	// cout<<s4<<endl;
	// cout<<s5<<endl;

	// if(s0.empty()){
	// 	cout<<"Empty String"<<endl;
	// }

	// //Appending Strings
	// s0.append("I love C++");
	// cout<<s0<<endl;
	// s0+=" and Python";
	// cout<<s0<<endl;
	// cout<<s0.length()<<endl;
	// s0.erase();
	// cout<<s0.length()<<endl;

	// //Comparing two Strings
	// s0="apple";
	// s1="mango";
	// cout<<s0.compare(s1)<<endl;
	// cout<<s1.compare(s0)<<endl;
	// cout<<s0.compare(s0)<<endl;

	// //overloading ">"
	// if(s1>s0){
	// 	cout<<"mango is lexiographical greater than apple"<< endl;
	// }

	// //find Substring
	// string s = "i want to have apple juice";
	// int idx = s.find("apple");
	// cout<<idx<<endl;

	// // Remove word from string
	// string word = "apple";
	// int len  = word.length();
	// s.erase(idx,len+1);
	// cout<<s<<endl;

	// //iterate over all the character in string
	// for(int i = 0 ;i <s1.length();i++){
	// 	cout<<s1[i]<<".";
	// }
	// cout << endl;

	// //for each loop
	// for(auto it:s1){
	// 	cout<<it<<":";
	// }
	// cout<< endl;

	// //iterators
	// for(auto it=s1.begin();it!=s1.end();it++){
	// 	cout<<(*it)<<endl;
	// }

	// int n;
	// cin>>n;
	// cin.get();
	// string s[100];

	// for(int i=0;i<n;i++){
	// 	getline(cin,s[i]);
	// }
	// //n -> number of string
	// //sort(s,s+n);
	// sort(s,s+n,compare);

	// for(int i =0;i<n;i++){
	// 	cout<<s[i]<<endl;
	// }

	/*String Tokenization used to break string into list of token
	Internally
	char * strtok(char * s, char * delimeter) -> returns character pointer, accept char array, abd also accept
	array of delimeter(about which we want to break the string)
	returns a token on each subsequent call
	on the first call function should be passed with string argument for 's'
	on subsequent calls we should pass the string argument aw null

	*/
	//char s[100] = "Today is a rainy day";
	// char *ptr = strtok(s," ");
	// cout<<ptr<<endl; // will get the first word

	// // ptr = strtok(s," ");//call again
	// // cout <<ptr <<endl;// will again get the first string

	// ptr points to the first token in the string but when we want to get the next token of the string we will
	// pass "NULL" nstead of string s when we pass Null strtok() maintains the static array that stores the state of
	// sting(means adter first call with string s it knows that it has covered "today" and jumps to next)

	// ptr = strtok(NULL," ");//call again
	// cout <<ptr <<endl;
	// ptr = strtok(NULL," ");//call again
	// cout <<ptr <<endl;

	// char *ptr = mystrtok(s, ' ');
	// cout << ptr << endl;

	// while(ptr!=NULL){
	// 	ptr=mystrtok(NULL,' ');
	// 	cout<<ptr<<endl;
	// }


	// char s[1000];
	// cin.getline(s, 1000);
	// space20(s);
	// cout << s;


	string s1,s2;
	cin>>s1>>s2;
	cout<<checkSubsequence(s1,s2)<<endl;


	return 0;

}
#include<bits/stdc++.h>
using namespace std;


// bool isBalanced(string input) {
// 	stack<char> st;
// 	for (auto ch : input) {
// 		switch (ch) {
// 		case '(':
// 		case '{':
// 		case '[': st.push(ch);
// 			break;
// 		case ')':
// 			if (!st.empty() and st.top() == '(') {
// 				st.pop();
// 			}
// 			else {
// 				return false;
// 			}
// 			break;
// 		case '}':
// 			if (!st.empty() and st.top() == '{') {
// 				st.pop();
// 			}
// 			else {
// 				return false;
// 			}
// 			break;
// 		case ']':
// 			if (!st.empty() and st.top() == '[') {
// 				st.pop();
// 			}
// 			else {
// 				return false;
// 			}
// 			break;
// 		default: continue;
// 		}
// 	}

// 	if (st.empty()) {
// 		return true;
// 	}
// 	return false;
// }


// int longeestValidParantheses(string s){
// 	stack<int>st;
// 	st.push(-1);
// 	int max_length=0;
// 	for(int i=0;i<s.length();i++){
// 		if(s[i]=='('){
// 			st.push(i);
// 		}
// 		else{
// 			st.pop();
// 			if(st.empty()){
// 				st.push(i);
// 			}
// 			else{
// 				max_length=max(max_length,i-st.top());
// 			}
// 		}
// 	}
// 	return max_length;
// }


// string SimplifyPath(string path){
// 	istringstream iss(path);

// 	vector<string> tokens;
// 	string token;
// 	while(getline(iss, token, '/')){
// 		if(token =="." or token==""){
// 			continue;
// 		}
// 		tokens.push_back(token);
// 	}

// 	vector<string> stack;
// 	if(path[0]=='/'){
// 		stack.push_back("");
// 	}

// 	for(string token:tokens){
// 		if(token == ".."){
// 			if(stack.size()==0 or stack[stack.size()-1]==".."){
// 				stack.push_back("..");
// 			}
// 			else if(stack[stack.size()-1] != ""){
// 				stack.pop_back();
// 			}
// 		}
// 		else{
// 			stack.push_back(token);
// 		}
// 	}

// 	//corner case when we have only single element
// 	if(stack.size()==1 and stack[0]==""){
// 		return "/";
// 	}

// 	ostringstream oss;
// 	int i=0;
// 	for(auto token:stack){
// 		if(i!=0){
// 			oss<< "/";
// 		}i++;
// 		oss<<token;
// 	}

// 	return oss.str();

// }

// class fun {
// public:
// 	void operator()() {
// 		cout << "Having fun inside operator() fun!" << endl;
// 	}
// 	void operator()(string s) {
// 		cout << "Having fun inside operator() fun! with " << s << endl;
// 	}
// };


// class person{
// public:
// 	string name;
// 	int age;
// 	person(){

// 	}
// 	person(string n, int a){
// 		name=n;
// 		age=a;
// 	}
// };

// class personCompare{
// public:
// 	bool operator()(person A, person B){
// 		cout<<"Comparing " <<A.age <<" with " <<B.age<<endl;
// 		return A.age< B.age;
// 	}
// };


// void query_point(priority_queue<int,vector<int>,greater<int> > pq){
// 	while(!pq.empty()){
// 		cout<<pq.top()<<",";
// 		pq.pop();
// 	}
// 	cout<<endl;
// }

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	// string s = "{a+(b+c)+([d+e]*f))}+k+((a+b+c)+[d])";
	// //{a+(b+c)+([d+e]*f))}+k

	// if (isBalanced(s)) {
	// 	cout << "Balanced!" << endl;
	// }
	// else {
	// 	cout << "Not Balanced!" << endl;
	// }

	// string s = "())";
	
	// cout << longeestValidParantheses(s) << endl;


	// queue<char>q;
	// int freq[27] = {0};

	// char ch;
	// cin>>ch;

	// while(ch!= '.'){
	// 	//reading stream of character untill "."
	// 	q.push(ch);
	// 	freq[ch-'a']++; 
	// 	//storing frequency of each alphabet at its same position in english language like c-a=2 so freq of c will be 
	// 	//stored at 2nd index by incrementing each time

	// 	//query -> Now removing all chars from front of queue which have frequency greater than 1

	// 	while(!q.empty()){
	// 		int idx=q.front()-'a';  
	// 		//finding index of alphabet by subtracting from 'a' to check the freq of that character
	// 		if(freq[idx]>1){
	// 			q.pop();
	// 		}
	// 		else{
	// 			cout<<q.front()<<endl;
	// 			break;
	// 		}
	// 	}
	// 	if(q.empty()){
	// 		cout<<"-1"<<endl;
	// 	}
	// 	cin>>ch;//reading next character
	// }//end of while loop

    // string path = "/../x/y/../z/././w/a///../../c/./";

    // cout << SimplifyPath(path) << endl;

	// priority_queue<int>pq_max; //by default it is max heap means max value has max priority
	// priority_queue<int, vector<int>, greater<int> > pq_min; //it is min heap;

	// int nElement;
	// cin>>nElement;
	// for(int i=1;i<=nElement;i++){
	// 	int no;cin>>no;
	// 	pq_max.push(no); //push() takes O(LogN)
	// 	pq_min.push(no);
	// }

	// //remove elements from heap
	// while(!pq_max.empty()){
	// 	cout<<pq_max.top()<<" ";	//top()-> O(1)
	// 	pq_max.pop();	//pop()-> O(LogN)
	// }
	// cout<<endl;

	// //remove elements from heap
	// while(!pq_min.empty()){
	// 	cout<<pq_min.top()<<" ";	//top()-> O(1)
	// 	pq_min.pop();	//pop()-> O(LogN)
	// }


	// fun f; // f is the object of fun class (constructor call)
	// f();   //overloaded() operator looks like function call with class object f.
	// //f is an object but behaves like function call so f is called functors(functional object)
	// f("C++");
	
	// int n;
	// cin>>n;
	// priority_queue<person,vector<person>,personCompare>pq;
	// for(int i=0;i<n;i++){
	// 	string name;
	// 	int age;
	// 	cin>>name>>age;
	// 	person p(name,age);
	// 	pq.push(p);
	// }
	// int k=3;
	// for(int i=0;i<k;i++){
	// 	person p=pq.top();
	// 	cout<<p.name<<" " <<p.age<<endl;
	// 	pq.pop();
	// }

	// int key=3;
	// int no, cs=0; //cs-> this will ensure the max limit of the heap size
	// priority_queue<int,vector<int>,greater<int> >pq;
	// while(scanf("%d", &no)!=EOF){
	// 	if(no==-1){
	// 		//print the k-largest element as query point has occured from the elements before -1
	// 		query_point(pq);
	// 	}
	// 	else if(cs<key){
	// 	//means current size of heap is less than k push number from running stream ans increment current size of heap
	// 		pq.push(no);
	// 		cs++;
	// 	}
	// 	else{
	// 		if(no>pq.top()){
	// 			//if number in running stream is greater than the number at the top of heap
	// 			pq.pop();
	// 			pq.push(no);
	// 		}
	// 	}
	// }

	// priority_queue<int>leftheap; //max Heap
	// priority_queue<int,vector<int>,greater<int>>rightheap; //min heap

	// int d;
	// cin>>d;
	// leftheap.push(d);
	// float median=d;
	// cout<<median<<" ";
	// cin>>d;
	// while(d!=-1){
	// 	if(leftheap.size() > rightheap.size()){
	// 	//as esme size unequal (odd) h heap ka toh jabnew element push karege toh even number of element ho 
	// 	//jayege toh median average to 2 middle number hoga
	// 		if(d<median){
	// 			//eska matlab h ki jo d element h voh leftheap m jana chahiye becoz voh chota h median se bhut
	// 			//leftheap phele se size m badi h toh rebalancing hogi phele
	// 			rightheap.push(leftheap.top());
	// 			leftheap.pop();
	// 			leftheap.push(d);
	// 		}
	// 		else{
	// 			rightheap.push(d);
	// 		}
	// 		median=(leftheap.top()+rightheap.top())/2.0;
	// 	}
	// 	else if(leftheap.size()==rightheap.size()){
	// 		if(d<median){
	// 			leftheap.push(d);
	// 			median=leftheap.top();
	// 		}
	// 		else{
	// 			rightheap.push(d);
	// 			median=rightheap.top();
	// 		}
	// 	}
	// 	else{
	// 		//leftheap.size()<rightjheap.size()
	// 		if(d<median){
	// 			leftheap.push(d);
	// 		}
	// 		else{
	// 			leftheap.push(rightheap.top());
	// 			rightheap.pop();
	// 			rightheap.push(d);
	// 		}
	// 		median=(leftheap.top()+rightheap.top())/2.0;
	// 	}
	// 	cout<<median<<" ";
	// 	cin>>d;
	// }

	// int k;
	// cin >> k;
	// vector<vector<int> > a(k);
	// for (int i = 0; i < k; i++) {
	// 	int size;//size of each array
	// 	cin >> size;

	// 	a[i] = vector<int>(size);
	// 	for (int j = 0; j < size; j++) {
	// 		cin >> a[i][j];
	// 	}
	// }

	// vector<int>idx(k, 0);
	// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
	// //ye starting m har array se phele phele element utha liya
	// for (int i = 0; i < k; i++) {
	// 	pair<int,int>p;
	// 	p.first=a[i][0];
	// 	p.second=i;
	// 	pq.push(p);
	// }
	// vector<int> ans;
	// while (!pq.empty()) {
	// 	pair<int, int> x = pq.top();
	// 	pq.pop();
	// 	ans.push_back(x.first);
	// 	if (idx[x.second] + 1 < a[x.second].size()) {
	// 		//ye wala voh case h jab abhi array m element bache hue agar ulta hota toh matlab index wale array
	// 		//me voh array size bada index store kiya hua jisper ja nahi sakte
	// 		 pair<int,int>p;
 // 			 p.first=a[x.second][idx[x.second] + 1];
 // 			 p.second=x.second;
	// 		pq.push(p);
	// 	}
	// 	idx[x.second] += 1;
	// }

	// for (int i = 0; i < ans.size(); i++) {
	// 	cout << ans[i] << endl;
	// }
	// cout << endl;



	unordered_map<string,int>ourMap;

	//insert
	pair<string,int>p ("abc", 1);
	ourMap.insert(p);

	ourMap["def"] = 2;

	//find or Access

	cout<<ourMap["abc"]<<endl;
	cout<<ourMap.at("abc")<<endl;
	cout<<ourMap["def"]<<endl;

	cout<<"Size: " <<ourMap.size()<<endl;
	//This will show error
	//cout<<ourMap.at("ghi")<<endl;
	cout<<ourMap["ghi"]<<endl;
	cout<<"Size: " <<ourMap.size()<<endl;


	//check presence
	if(ourMap.count("ghi")>0){
		cout<<"ghi is present" << endl;
	}

	//erase
	ourMap.erase("ghi");
	cout<<"Size: " <<ourMap.size()<<endl;
	if(ourMap.count("ghi")>0){
		cout<<"ghi is present" << endl;
	}
	else{
		cout<<"ghi is being erased"<<endl;
	}
	

	return 0;

}






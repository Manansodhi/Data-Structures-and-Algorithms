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



int SearchNearlySortedArray(int arr[], int n, int ele) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == ele)
			return mid;
		if (mid - 1 >= start && arr[mid - 1] == ele)
			return mid - 1;
		if (mid + 1 <= end && arr[mid + 1] == ele)
			return mid + 1;
		else if (arr[mid] >= ele)
			end = mid - 2;
		else
			start = mid + 2;
	}
	return 0;
}

int floorOfElement(int arr[], int n, int ele) {
	int start = 0, end = n - 1;
	int res;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == ele)
			return arr[mid];
		if (arr[mid] <= ele) {
			res = arr[mid];
			start = mid + 1;
		}
		else if (arr[mid] >= ele)
			end = mid - 1;
	}
	return res;
}

int ceilOfElement(int arr[], int n, int ele) {
	int start = 0, end = n - 1;
	int res;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == ele)
			return arr[mid];
		if (arr[mid] <= ele) {
			start = mid + 1;
		}
		else if (arr[mid] >= ele) {
			res = arr[mid];
			end = mid - 1;
		}
	}
	return res;
}


int minDiffElement(int arr[], int key, int n) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key) {
			return arr[mid];
		}
		else if (arr[mid] >= key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	int left_neighnour = arr[end], right_neighbour = arr[start];
	if (abs(left_neighnour - key) > abs(right_neighbour - key)) {
		return right_neighbour;
	}
	return left_neighnour;
}

int TimesSortedArrayRotated(int arr[], int n) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		int prev = (mid + n - 1) % n;
		int next = (mid + 1) % n;
		if (arr[mid] < arr[next] && arr[mid] < arr[prev]) {
			return mid;
		}
		else if (arr[mid] < arr[end]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return 0;
}

int binarysearch(int arr[], int n, int ele) {
	int start = 0, end = n - 1;
	int mid = start + ((end - start) / 2);
	while (start <= end) {
		if (arr[mid] == ele) {
			return mid;
		}
		else if (arr[mid] > ele) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return -1;
}

int binarysearchReverseSorted(int arr[], int n , int ele) {
	int start = 0, end = n - 1;
	int mid = start + ((end - start) / 2);
	while (start <= end) {
		if (arr[mid] == ele) {
			return mid;
		}
		else if (arr[mid] > ele) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}

int firstOccurence(vector<int>&nums, int target) {
	int n = nums.size();
	int start = 0, end = n - 1, firstOccur = -1;
	int mid = start + ((end - start) / 2);
	while (start <= end) {
		if (nums[mid] == target) {
			firstOccur = mid;
			end = mid - 1;
		}
		else if (nums[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return firstOccur;
}

int lastOccurence(vector<int>&nums, int target) {
	int n = nums.size();
	int start = 0, end = n - 1, lastOccur = -1;
	int mid = start + ((end - start) / 2);
	while (start <= end) {
		if (nums[mid] == target) {
			lastOccur = mid;
			start = mid + 1;
		}
		else if (nums[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return lastOccur;
}

int firstOccur(int arr[], int start, int end, int key) {
	int mid = start + (end - start) / 2, res = -1;
	if (arr[mid] == key) {
		res = mid;
		end = mid - 1;
	}
	else {
		start = mid + 1;
	}
	return res;
}


int firstPosition(int arr[], int key) {
	int start = 0, end = 1;
	while (arr[end] < key) {
		start = end;
		end = end * 2;
	}
	return firstOccur(arr, start, end, key);
}

int maxInarr(int arr[], int n) {
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int SumOfElementOfArray(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

bool isValid(int arr[], int n, int k, int mx) {
	int student = 1, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum > mx) {
			student++;
			sum = arr[i];
		}
		if (student > k) {
			return false;
		}
	}ś
	return true;
}

int allocateMinPages(int arr[], int n, int k) {
	if (n < k) {
		return -1;
	}
	int start = maxInarr(arr, n), end = SumOfElementOfArray(arr, n), res = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (isValid(arr, n, k, mid)) {
			res = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return res;
}


bool isvalid(vector<int>&nests, int birds, int mx) {
	int BirdsRequired = 1, last_location = nests[0], noOfNests = nests.size();
	for (int i = 1; i <= noOfNests - 1; i++) {
		int current_location = nests[i];
		if (current_location - last_location >= mx) {
			cout << "        B" << i << " current_location-last_location: " << current_location - last_location << endl;
			BirdsRequired++;
			last_location = current_location;
		}

		if (BirdsRequired == birds) {
			return true;
		}
	}
	return false;
}

int angeryBirds(vector<int>&nests, int birds) {

	int n = nests.size();
	int result = -1;
	int start = 0, end = nests[n - 1] - nests[0];

	if (n < birds)
		return -1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		cout << "1 Mid: " << mid << " Start: " << start << " End: " << end << endl;
		if (isvalid(nests, birds, mid)) {
			cout << "2 Mid: " << mid << " Start: " << start << " End: " << end << endl;
			result = mid;
			start = mid + 1;
			cout << "2.1 Mid: " << mid << " Start: " << start << " End: " << end << endl;
		}
		else {
			end = mid - 1;
			cout << "3 Mid: " << mid << " Start: " << start << " End: " << end << endl;
		}
	}
	return result;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//int arr[] = {12,15,18,2,5,6,8,11};
	//int arr[] = {1,2,3,4,5,6,7,8,9};
	int arr[] = {10, 20, 30, 40};
	int n = sizeof(arr) / sizeof(arr[0]);
	// int ele=3;
	//cout<<TimesSortedArrayRotated(arr,n)<<endl;
	//cout<<allocateMinPages(arr,n,2)<<endl;

	int birds = 3;
	vector<int> nests{1, 2, 4, 8, 9};
	cout << angeryBirds(nests, birds) << endl;
	// int arr[] = {0,0,0,0,0,0,1,1,1,1,1,1,};
//    int ans = firstPosition(arr, 1);
//    if (ans==-1)
//        cout << "Element not found";
//    else
//        cout << "Element found at index " << ans;
//    return 0;
	//cout<<binarysearch(arr,n,20)<<endl;
	//cout<<binarysearchReverseSorted(arr,n,2+0)<<endl;
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



	// unordered_map<string,int>ourMap;

	// //insert
	// pair<string,int>p ("abc", 1);
	// ourMap.insert(p);

	// ourMap["def"] = 2;

	// //find or Access

	// cout<<ourMap["abc"]<<endl;
	// cout<<ourMap.at("abc")<<endl;
	// cout<<ourMap["def"]<<endl;

	// cout<<"Size: " <<ourMap.size()<<endl;
	// //This will show error
	// //cout<<ourMap.at("ghi")<<endl;
	// cout<<ourMap["ghi"]<<endl;
	// cout<<"Size: " <<ourMap.size()<<endl;


	// //check presence
	// if(ourMap.count("ghi")>0){
	// 	cout<<"ghi is present" << endl;
	// }

	// //erase
	// ourMap.erase("ghi");
	// cout<<"Size: " <<ourMap.size()<<endl;
	// if(ourMap.count("ghi")>0){
	// 	cout<<"ghi is present" << endl;
	// }
	// else{
	// 	cout<<"ghi is being erased"<<endl;
	// }


	return 0;

}






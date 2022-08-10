

//Using 2-pointer(lef, right)
void f(int left,int right,vector<int> &arr){
	if(left>=right)
		return;
	swap(arr[left],arr[right]);
	f(left++, right--, arr);
}


int main(){
	int n;
	cin>>n;
	vector<int> arr(n);

	f(0,n-1,arr);
	return 0;
}


//Using 1-variable
void f(int i, vector<int> &arr){
	int n=arr.size();
	if(i>=n/2)
		return;
	swap(arr[i],arr[n-i-1]);
	f(i++, arr);
}
int main(){
	int n;
	cin>>n;
	vector<int> arr(n);

	f(0,arr);
	return 0;
}
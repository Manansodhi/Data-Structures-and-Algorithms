
//T.C --> O(N) //calling recursive function N times
//S.C--> O(N) //Stack m 'N' function call will be waiting jab tak base condn na execute ho jaye

void f(int i,int n){
	//base case
	if(i>n)
		return;
	cout<<"Manan"<<endl;
	f(i+1,n);
}

int mani(){
	int n;
	cin>>n;
	f(1,n);
}
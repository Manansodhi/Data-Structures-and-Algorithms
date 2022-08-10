
//1-->N
void f(int i,int n){
	if(i==n)
		return n;
	cout<<i<<endl;
	f(i++,n);
}


int main(){
	int n;
	cin>>n;
	f(1,n);
}


//N-->1
void f(int i, int n){
	if(i==n)
		return 1;
	cout<<n<<endl;
	f(i,n--);
}

int main(){
	int n;
	cin>>n;
	f(1,n);
}

//OR

void f(int i, int n){
	if(i<=1)
		return ;
	cout<<i<<endl;
	f(i--,n);
}

int main(){
	int n;
	cin>>n;
	f(n,n);
}
 // Print 1 to N using backtracking but not allowed to use i++

//         3      3
void f(int i, int n){
	if(i<1)
		return;
	f(i-1,n);
	cout<<i<<endl;
}

     //     3    f(3,3)	
    // 	          /   cout<<i; will not be executed
   //     2	   f(2,3) 
  // 	        /    cout<<i; will not be executed
 //      1   f(1,3)
//            /     cout<<i; will not be executed
//         f(0,3)---> when this base condn get executed now when it will return now it will print 'i'  


int main(){
	int n;
	cin>>n;
	f(n,n);
}



 // Print N to 1 using backtracking but not allowed to use i--
void f(int i, int n){
	if(i>n)
		return;
	f(i++,n);
	cout<<i<<endl;
}

    //     1    f(1,3)	
    // 	          /   cout<<i; will not be executed
   //     2	   f(2,3) 
  // 	        /    cout<<i; will not be executed
 //      3   f(3,3)
//            /     cout<<i; will not be executed
//         f(4,3)---> when this base condn get executed now when it will return now it will print 'i'  



int main(){
	int n;
	cin>>n;
	f(1,n);
}
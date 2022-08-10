// Sum of first N  numbers
// n=3 --> ans =1+2+3==6


//Functional Recursion --> here we don't want the parameter to do the work. here we write recursive function
//and here we want the fuction to return answer and do not print the answer

//n=3
// f(3)=3+f(2)=3+3=>6
// f(2)=2+f(1)=2+1=>3
// f(1)=1+f(0)=1+0=>1
// f(0)=0

// Recurrence Relation
// f(n)=n+f(n-1);


int f(int n){
	if(n==0)
		return 0;
	return n+f(n-1);
}

//				f(3)     ==> 6
//				 /	
// 			   3+f(2)      ==>3+3  ==>6
//				  /	
//				 2+f(1)	   ==>2+1  ==>3
//					/
//				   1+f(0)	==> 1+0 ==>1
//					  /	
//   				 0	


int main(){
	int n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
}
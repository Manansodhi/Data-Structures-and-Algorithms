// Sum of first N  numbers
// n=3 --> ans =1+2+3==6

//Parameterized becoz here we increase parameter(sum) and then print that also

void f(int i, int sum){
	if(i<1)
		cout<<sum<<endl;
	func(i--,sum+i);
}

//                          f(3,0)
//							 /
//						   f(2,3)
//							/
//						  f(1,5)
//   					   /
//						 f(0,6)	 ans =6


 int main(){
 	int n;
 	cin>>n;
 	f(n,0);
 } 
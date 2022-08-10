
//T.C --> O(N)
//S.C --> O(N)

int factorial(int n){
	if(n==0)
		return 1;
	return n*factorial(n-1);
}
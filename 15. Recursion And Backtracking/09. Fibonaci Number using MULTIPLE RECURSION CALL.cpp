//Iterative
f[0]=0;f[1]=1;
for(int i=2;i<n;i++){
	f[i]=f[i-1]+f[i-2];
}


//Recursion
//time - O(2^n)
int f(int n){
	if(n<=1)
		return n;

	int last = f(n-1);
	int secondLast = f(n-2);

	return last+secondLast;
}
//find largest Number smaller than X in a sorted array if not present print -1

a[]={1,4,4,4,4,9,9,10,11};
n=a.size();
int idx = lower_bound(a,a+n,x)-a;
idx--;
if(idx>=0){
	cout<<a[idx];
}
else{
	cout<<"-1";
}


//find Smallest Number greater than X in sorted array. if number doesnot exit print -1;

int idx = upper_bound(a,a+n,X);
if(idx<n){
	cout<Ma[idx];
}
else{
	cout<<"-1";
}
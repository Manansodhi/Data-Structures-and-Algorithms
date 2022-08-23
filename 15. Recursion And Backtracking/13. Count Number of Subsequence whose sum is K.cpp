

int PrintSubSequence(int idx, int k, int sum, int arr[], int n){

	//condition NOT satisfied
	//Strickly done if array contains postivies only
	if(sum>k)return 0;
	if(idx == n){
		//condition satisfied return true so that no further recursion call happen
		if(sum==k){
			return 1;
		}
		//condition NOT satisfied
		return 0;
	}

	//pick the particular index element into subsequence
	sum+=arr[idx];
	int l = PrintSubSequence(idx+1,k,sum,arr,n);
	
	sum-=arr[idx]; 
	//not pick the element then this element is not added in subsequence
	int r = PrintSubSequence(idx+1,k,sum,arr,n);

	return l+r;
}


int main(){
	int arr[] = {3,1,2};
	int n = 3, k=2;
	PrintSubSequence(0,k,0,arr,n);
	return 0;
}       
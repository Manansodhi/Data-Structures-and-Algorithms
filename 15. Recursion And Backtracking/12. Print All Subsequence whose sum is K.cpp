

void PrintSubSequence(int idx, int sum, int curr_sum, int arr[], int n, vector<int> &ds){

	//condition NOT satisfied
	//Strickly done if array contains postivies only
	if(curr_sum>sum)return 0;
	if(idx == n){
		//condition satisfied print subsequence
		if(curr_sum==sum){
			for(auto it:ds)
				cout<<it<<" ";
			cout<<endl;
		}
		//condition NOT satisfied
		return ;
	}

	
	ds.push_back(arr[idx]);
	//pick the particular index element into subsequence
	curr_sum+=arr[idx];
    PrintSubSequence(idx+1,sum,curr_sum,arr,n,ds);

	curr_sum-=arr[idx]; 
	ds.pop_back();
	//not pick the element then this element is not added in subsequence
	PrintSubSequence(idx+1,sum,curr_sum,arr,n,ds);

	
}


int main(){
	int arr[] = {3,1,2};
	int n = 3, sum=2;
	vector<int>ds;
	PrintSubSequence(0,sum,0,arr,n,ds);
	return 0;
}

//APPROCH 1 DECLARING GLOBAL VARIABLE
bool flag = false;//but this is not preferred to use global variable. instead we use funtional method
// in that we will pick and then check if subbsequence with sum k is formed then we return 
//without going to not pick codn else we will go for not pick condn  

void PrintSubSequence(int idx, int sum, int curr_sum, int arr[], int n, vector<int> &ds){

	//condition NOT satisfied
	//Strickly done if array contains postivies only
	
	if(idx == n){
		//condition satisfied print subsequence
		if(curr_sum==sum && flag == false){
			flag = true;
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


//APPROCH 2 

bool PrintSubSequence(int idx, int sum, int curr_sum, int arr[], int n, vector<int> &ds){

	//condition NOT satisfied
	//Strickly done if array contains postivies only
	
	if(idx == n){
		//condition satisfied print subsequence
		if(curr_sum==sum){
			for(auto it:ds)
				cout<<it<<" ";
			cout<<endl;
			return true;
		}
		//condition NOT satisfied
		else 
			return false;
	}

	
	ds.push_back(arr[idx]);
	//pick the particular index element into subsequence
	curr_sum+=arr[idx];
    if(PrintSubSequence(idx+1,sum,curr_sum,arr,n,ds) == true)
    	return true;

	curr_sum-=arr[idx]; 
	ds.pop_back();
	//not pick the element then this element is not added in subsequence
	if(PrintSubSequence(idx+1,sum,curr_sum,arr,n,ds) == true)
		return true;

	return false; 
}


int main(){
	int arr[] = {3,1,2};
	int n = 3, sum=2;
	vector<int>ds;
	PrintSubSequence(0,sum,0,arr,n,ds);
	return 0;
}
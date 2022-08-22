//Printing all subsequences of array
/*
arr = [3,1,2]
O/T --> {},3,1,2,{3,1},{1,2},{3,2},{3,1,2}

T.C --> O(2^n * n)
for each index we have couple of options pick and not pick and we have n index so it is 2^n 
and n for printing 

S.C --> O(n) max number of recursion taht will wait are 3 in stack space that is size of array n

*/

void printSubsequence(int idx, vector<int>& ds, int arr[], int n){
    if(idx==n){
        for(auto i:ds)
            cout<<it<<" ";
        cout<<endl;
    }
    //Take or pick the particular index into the subsequence
    ds.push_back(arr[idx]);
    printSubsequence(idx+1,ds,arr,n);

    //not pick or not take element to our subsequence
    ds.pop_back();
    printSubsequence(idx+1,ds,arr,n);
}


int main(){
    int arr[] = {3,1,2};
    int n=3;
    vector<int>ds;
    printSubsequence(0,ds,arr,n);
}
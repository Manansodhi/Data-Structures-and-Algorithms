#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int size;
	cin >> size;
	int * arr = new int [size];
	for (int i = 0; i < size; i++){
		cin >> arr[i];
	} 

	cout << kadane(arr, size) << endl;


    return 0;

}
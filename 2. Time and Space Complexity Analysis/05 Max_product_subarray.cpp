#include<bits/stdc++.h>
using namespace std;

//INPUT 1
// 5
// 6 -3 1 -10 2 
// OUTPUT 1 -> 360
// INPUT 2 
// 5
// 6 -3 -10 0 2
// OUTPUT 2 -> 180
// TIME O(N)   SPACE O(1)
int Max_Product_Subarray(int arr[], int n){
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 0;

    for (int i = 0; i < n; i++){
        if (arr[i] > 0){
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(1, min_ending_here * arr[i]);
        }
        else if(arr[i] < 0){
            int temp = max_ending_here;
            max_ending_here = max(1, min_ending_here * arr[i]);
            min_ending_here = temp * arr[i];
        }
        else{
            max_ending_here = 1;
            min_ending_here = 1;
        }
        
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far; 
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << Max_Product_Subarray(arr, n) << endl;
}
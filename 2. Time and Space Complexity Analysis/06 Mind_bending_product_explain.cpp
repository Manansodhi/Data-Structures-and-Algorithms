#include<bits/stdc++.h>
using namespace std;

// INPUT 1
// N 
// 5
// 10 3 5 6 2 
// OUTPUT 1
// 180 600 360 300 900
// INPUT 2
// 2 
// OUTPUT 2
// 12 20
// TIME :- O(N)
// SPACE :- O(1)

void Max_Product(int arr[], int n){
    long * p = new long int[n];
    long lp =1;
    for (int i = 0; i < n; i++){
        p[i] = lp;
        lp = lp * arr[i];
    }


    long rp = 1;
    for (int i = n-1; i >= 0; i--){
        p[i] = p[i] * rp;
        rp = rp * arr[i]; 
    }

    for (int i = 0; i < n; i++){
        cout << p[i] <<" ";
    }
    cout << endl;
}

 int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif    
     int t;
     cin >> t;

     while (t--){
         int n;
         cin >> n;
         int arr[n];
         for (int i = 0; i < n; i++){
             cin >> arr[i];
         }
        Max_Product(arr, n);
     }
     return 0;
 }
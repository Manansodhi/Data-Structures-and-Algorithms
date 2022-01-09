#include<bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin >> n;
    int ** arr = new int *[n];

    for(int i = 0; i < n; i++){
        arr[i] = new int [n];
    for(int j = 0; j < n; j++){
        cin >> arr[i][j];
    }    
 }


 for (int col = 0; col < n; col++){
     if ((col %2) == 0){
         for (int row = 0; row < n; row++){
             cout << arr[row][col] <<" " ;
         }
         cout << endl;
     }
     else{
         for (int row = n-1; row >= 0; row--){
             cout << arr[row][col] << " " ;
         }
         cout << endl;8
     }
 }

 for (int i = 0; i < n; i++){
     delete arr[i];
 }
 delete[]arr;
 return 0;
}

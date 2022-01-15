#include<bits/stdc++.h>
using namespace std;

//int main(){
    // int arr[] = {1, 10, 11, 9, 100};
    // int n = sizeof(arr)/sizeof(int);
    // int key = 13;  // when key is not present in the array find fumc will return the pointer to the last position of array


    //FIND FUMCTION
    // auto it = find(arr, arr+n, key); //find function returns pointer of that location
    // cout << it << endl;

    // int index = it-arr;
    // cout << index << endl;
    // if (index == n){
    //     cout << key <<" Not found" << endl;
    // }
    // else{
    //     cout << key << " Present at index " << index << endl;
    // }



    //BINARY SEACRH
    // int arr[] = {20, 30, 40, 40, 40, 40, 50, 100};
    // int n = sizeof(arr)/sizeof(int);
    // int key = 30;
    // bool present = binary_search(arr, arr+n, key); //binary_search() will return either true/false
    // if (present){
    //     cout << "presemt" << endl;
    // }
    // else{
    //     cout << "absent!" << endl;
    // } 


    // upper_bound()   lower_bound()  function 
    // int arr[] = {20, 30, 40, 40, 40, 50, 100};
    // int n = sizeof(arr)/sizeof(int);
    // int key = 40;
    // auto lb = lower_bound(arr, arr+n, 40); // it will return the addres of first element >= key
    // cout << (lb - arr) << endl;

    // auto ub = upper_bound(arr, arr+n, 40);
    // cout << (ub - arr) << endl;

    // cout << "occurance frequency of 40 is " << (ub-lb) << endl;

    //     return 0;

//}


    //sort() function

    // bool compare(int a, int b){
    //     return a < b;
    // }
    // int main(){
    // int n, key;
    // cin >> n;
    // int a[1000];
    // for (int i = 0; i < n; i++){
    //     cin >> a[i];
    // }

    // sort(a, a+n);
    // sort(a, a+n, greater<int>());
    // sort(a, a+n, compare);
    // for (int i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;



    //Bubble sort
//     bool compare(int a, int b){
//         return a > b;
//     }

//     void bubble_sort(int a[], int n, bool(&cmp)(int a, int b)){
//         //put n-1 large elements to the end
//         for (int itr = 1; itr <= n-1; itr++){
//             //pairwise swapping int the unsorted array
//             for (int j = 0; j <= (n-itr-1); j++){
//                 if (cmp(a[j], a[j+1])){
//                     swap(a[j], a[j+1]);
//                 }
//             }
//         }
//     }
    int main(){
    int n, key;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    //bubble_sort(a, n, compare);

   // rotate(a, a+2, a+n);

   //next_permutation(a, a+n);

   reverse(a+2, a+n);


    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;



    return 0;
}
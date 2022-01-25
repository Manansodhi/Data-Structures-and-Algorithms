/*You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
Note:Change in the input array/list itself. You don't need to return or print the elements.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.
Third line contains the value of 'D' by which the array/list needs to be rotated.

Output Format :
For each test case, print the rotated array/list in a row separated by a single space.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^4
0 <= N <= 10^6
0 <= D <= N

Time Limit: 1 sec

Sample Input 1:
1
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2

Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2
Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2

*/

#include<bits/stdc++.h>
using namespace std;

// //1. Approch Naive
// //TIME :- O(N*D) = O(10^12) =>TLE 

// void Rotate_Array_left_By_D_position(int * arr, int size, int d){
//     int temp;
//     while(d--){
//         temp = arr[0];
//         for(int i = 0; i < size; i++){
//             arr[i] = arr[i+1];
//         }
//         arr[size-1] = k;
        
//     }
//     arr[size-1] = temp;
//     for(int i =0;i <size;i++){
//         cout << arr[i] <<" " ;
//     }
//     cout << endl;
// }


//2. Approch 
// Every element will be displaced from its current position by d position
//Time :- O(N)
//Space :- O(d)
void Rotate_Array_left_By_D_position(int *arr, int size, int d){
    int temp[d];
    for(int i = 0; i <d;i++){
        temp[i] = arr[i];
    }

    for(int i = 0; i < size-d;i++){
        arr[i] = arr[i+d];
    }
    for(int i = size-d,j=0; i< size;i++,j++){
        arr[i] = temp[j];
    }
     for(int i =0;i <size;i++){
        cout << arr[i] <<" " ;
    }
    cout << endl;
}


//3. Approch By Reversing the array twice
//Time :- O(N)
//Space :- O(1)

void rotator(int *arr, int low, int high){
    while(low<high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}

void Rotate_Array_left_By_D_position(int* arr, int size,int d){
    if(d>=size && size!=0)
        d = d%size; // like the array size is 5 and d=8 so array doesnot get changed in first 5 reverse but effectively get reversed in 3 so (d%size)
    else if(size==0)
        return;
    rotator(arr,0,size-1);
    rotator(arr, size-d, size-1);
    rotator(arr, 0, size-d-1);
    for(int i =0;i <size;i++){
        cout << arr[i] <<" " ;
    }
    cout << endl;    
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        int d;
        cin >> d;
        Rotate_Array_left_By_D_position(arr, size, d);
    }
    return 0;
}
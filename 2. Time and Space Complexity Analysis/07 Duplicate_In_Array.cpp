/* Duplicate in array

You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). 
Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging 
from 0 to 3, and among these, there is a single integer value that is present twice. You need to find
 and return that duplicate number present in the array.
Note : Duplicate number is always present in the given array/list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.

Output Format :
For each test case, print the duplicate element in the array/list.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec

Sample Input 1:
1
9
0 7 2 5 4 7 1 3 6

Sample Output 1:
7

Sample Input 2:
2
5
0 2 1 3 1
7
0 3 1 5 4 3 2

Sample Output 2:
1
3

*/

#include<bits/stdc++.h>
using namespace std;
/*
1. Naive Approch

  0 - (n-2) <= values of elements => total (n-1) elements
  campare each element of array with remaining n-1, n-2, ....., 1 elements
  TIME :- O(n^2)
  Space :- O(1)

2. Sorting Approch
   sort the array in O(log n) and then compare two consective elements if they are same return that it
   will take O(n)
   TIME :- O(log n)
   Space :- O(1)

3. Optimized Approch
   find sum of all elements of array in O(n) time and then also find the sum of first (n-2) natural numbers 
   becoz we know that we have elements of array btw 0 - (n-2) it will take O(1)time direct formula   
   TIME :- O(n)
   Space :- O(1)

*/
int duplicate_in_array(int * arr, int size){
	//TIME- O(n)
	int sum  =0 ;
	for(int i = 0;i<n;i++){
		sum = sum +arr[i];
	}
	return (sum - ((size-2)*(size-1)/2));
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif    
     int t;
     cin >> t;

     while (t--){
         int size;
         cin >> size;
         int arr[size];
         for (int i = 0; i < size; i++){
             cin >> arr[i];
         }
        cout << duplicate_in_array(arr, size) << endl;
     }
     return 0;
 }

/*
Find the Unique Element
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].Now,in the given array/list, 
'M' numbers are present twice and one number is present only once.You need to find and return that number which is unique in 
the array/list.
Note:
Unique element is always present in the array/list according to the given condition.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.

Output Format :
For each test case, print the unique element present in the array.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec

Sample Input 1:
1
7
2 3 1 6 3 6 2
Sample Output 1:
1

Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7
Sample Output 2:
4
10

*/


#include<bits/stdc++.h>
using namespace std;

/* 1. Approch Naive
   Time :- O(N^2)
*/

int find_Unique_Element(int * arr, int size){
	for(int i=0;i<size;i++)
		for(int j=i+1;j<size;j++){
			if(arr[i]==arr[j]){

			}
		}
}


/*
using Sorting and then checking consecutive elements in the array
Time :- O(Nlog N)
Space :- O(1)

Ex - 6,1,6,3,4,3,1
sorting -> 1,1,3,3,4,6,6
output-> 4
*/


/*
Using Hashmap(maintain the count of each element)
Time :- O(N)
Space :- O(N)
*/


/*
 Using XOR Operator (bitwise Operator)
    Properties of XOR operator
    X^X = 0 
    X^0 = X
   Time :- O(N) 
   Space :- O(1)
*/
int find_Unique_Element(int * arr, int size){
	int all = 0;
	for(int i=0; i<size; i++){
		cin >> arr[i];
		all ^= arr[i];
	}
	return all;
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

        find_Unique_Element(arr, size);
    }
    return 0;
}
/*Triplet sum

You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
Note :Given array/list can contain duplicate elements.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the first array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.
Third line contains an integer 'X'.

Output format :
For each test case, print the total number of triplets present in the array/list.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec

Sample Input 1:
1
7
1 2 3 4 5 6 7
12
Sample Output 1:
5

Sample Input 2:
2
7
1 2 3 4 5 6 7
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5

Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.
For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)

*/


#include<bits/stdc++.h>
using namespace std;

/*
Approch 1 :- BRUTE FORCE APPROCH
TIME O(N^3)
SPACE O(1)
*/
int Triplet_sum(int * arr, int size, int X) {
    int count = 0;
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (arr[i] + arr[j] + arr[k] == X) {
                    count++;
                }
            }
        }
    }
    return count;
}

/*
Approch 2:- Sorting -> 2 pointer technique 
SPACE :- O(1)
TIME :- O(N^2) => Only 2 nested loop traversing array. 2 pointer technique takes O(N)
Two pointer technique take linear time better than nested loop
 1. sort 
 2. fix 1rst element of triplet  = arr[i]
 3. fix 2 pointer ,at (i+1) amd (n-1) position and look at the sum of triplet
   3.1 if sum is smaller than X then increment the pointer
   3.2 else if the sum is bigger decrease the end pointer to reduce the sum 
   3.3 else sum of 2 pointer is equal to X(required sum) then print the triplet 
*/

int tripletSum(int * arr, int size, int X){
    int count = 0;
    sort(arr,arr+size);
    int start, end;
    for(int i =0;i<size-2;i++){
         if(i==0 || (i>0 && arr[i]!=arr[i-1])){
            start=i+1;
            end = size-1;
            while(start < end){
                if(arr[i]+arr[start]+arr[end] >X){
                    end--;
                 }
                else if(arr[i]+arr[start]+arr[end]<X){
                    start++;
                }
                else{
                    count++;
                    while(start<end && arr[start]==arr[start+1])
                    start++;
                    while(start<end && arr[end] == arr[end-1])
                    end--;
                    end--;start++;
                }
            }
         }
    }
    return count;
}


 // vector<vector<int>> threeSum(vector<int>& num) {
 //        vector<vector<int>> res; 
 //        sort(num.begin(), num.end()); 
        
 //        // moves for a
 //        for (int i = 0; i < (int)(num.size())-2; i++) {
            
 //            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
 //                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
 //                while (lo < hi) {
 //                    if (num[lo] + num[hi] == sum) {
                        
 //                        vector<int> temp; 
 //                        temp.push_back(num[i]); 
 //                        temp.push_back(num[lo]); 
 //                        temp.push_back(num[hi]); 
 //                        res.push_back(temp);
                        
 //                        while (lo < hi && num[lo] == num[lo+1]) lo++;
 //                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
 //                        lo++; hi--;
 //                    } 
 //                    else if (num[lo] + num[hi] < sum) lo++;
 //                    else hi--;
 //               }
 //            }
 //        }
 //        return res;
 //    }




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
        int X ;
        cin >> X;
        cout << Triplet_sum(arr, size, X) << endl;
    }
    return 0;
}

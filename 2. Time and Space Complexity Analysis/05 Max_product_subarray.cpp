/*
You are given an array “arr'' of integers. Your task is to find the contiguous subarray within the array which has the largest
 product of its elements. You have to report this maximum product.

For Example:
If arr = {-3,4,5}.
All the possible non-empty contiguous subarrays of “arr” are {-3}, {4}, {5}, {-3,4}, {4,5} and {-3,4,5}.
The product of these subarrays are -3, 4, 5, -12, 20 and -60 respectively.
The maximum product is 20. Hence, the answer is 20.

Constraints:
1 <= T <= 100
1 <= N <= 5000
-100 <= arr[i] <= 100
where N is the size of the array “arr”.
Time limit: 1 second

Sample Input 1:
2
4
3 5 -2 -4
5
2 4 3 5 6
Sample Output 1:
120
720

Sample Input 2:
2
4
6 0 2 -4
3
-1 -3 -4
Sample Output 2:
6
12
*/

#include"bits/stdc++.h"
using namespace std;

/*
Brute-force
Steps:

1 Create an ans variable and initialize it to INT_MIN.
2 Run a loop i = 0 to N and do:
   Run a loop j = i to N and do:
     Create a variable, say currentProduct and initialize it to 1.
     Run a loop k = i to j and do:
        currentProduct = currentProduct * arr[k]
        Store the maximum of ans and the currentProduct in the ans variable.
3 Finally, return the ans variable.

Time Complexity
O(N^3), where N denotes the number of elements of arr.
As there are N*(N+1)/2 subarrays in total, and we are iterating over every subarray in linear time, the overall time complexity 
will be O(N^3).  

Space Complexity
O(1) Constant space is used.

*/

int maximumProduct(vector<int> &arr, int n){
    
    int ans = INT_MIN;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){

            int currentProduct = 1;
            for(int k = i; k <= j; k++){
                currentProduct = currentProduct * arr[k];
                ans = max(ans, currentProduct);
            }
        }
    }

    return ans;
}


/*
Optimized Brute-force
Steps:

Create an ans variable and initialize it to INT_MIN.
Run a loop i = 0 to N and do:
Create a variable, say currentProduct and initialize it to arr[i].
Store the maximum of ans and the currentProduct in the ans variable.
Run a loop from j = i + 1 to N and do:
currentProduct = currentProduct * arr[j].
Store the maximum of “ans” and the “currentProduct” in the “ans” variable.
Finally, return the “ans” variable.
Time Complexity
O(N^2), where N denotes the number of elements of arr.

 

We are visiting all the subarrays with the help of two nested loops. As there are N*(N+1)/2 subarrays in total, the time complexity will be O(N^2).

Space Complexity
O(1)Constant space is used.

*/

int maximumProduct(vector<int> &arr, int n){
    
    int ans = INT_MIN;

    for(int i = 0; i < n; i++){
        int currentProduct = arr[i];
        ans = max(ans, currentProduct);

        // Find all possible subarrays starting from this current index. 
        for(int j = i + 1; j < n; j++){
            currentProduct = currentProduct * arr[j];
            ans = max(ans, currentProduct);
        }
    }

    return ans;
}


/*
Dynamic Programming
In the previous approach, we were trying to find the product of all the possible subarrays of the array. But, we can optimize 
 approach with a simple trick. Note that the product of an even number of negative integers is a positive integer. 
Now, let’s say the number of negative integers in a subarray of the array is P. If P is even, then we should take all the 
negative integers as the product of these elements will be positive. If P is odd, then we have to take P - 1 negative integer. 
Since this has to be a contiguous subarray, so we can either exclude one negative integer from the beginning or from the end.
So, we can take two integers to calculate the product from the beginning and the product from the end of the array. We will 
traverse the array “arr”, multiply arr[i] with the product from the beginning and arr[N - i - 1] with the product from the end. 
Then calculate the maximum of these two products in every iteration. Also, if at any point, if we encounter a 0, i.e. if either 
of the products become 0, then make that product 1 again.


Steps:

1 Create an ans variable and initialize it to INT_MIN. Create two more integers i.e. productFromFront, productFromBack. 
  Initialize them to 1.
2 Now for each i from 0 to N - 1:
    productFromFront = productFromFront * arr[i]
    productFromBack = productFromBack * arr[N - i - 1]
    Store the maximum of ans, productFromFront and productFromBack in the ans variable.
    If productFromFront becomes 0, make productFromFront = 1.
    If productFromBack becomes 0, make productFromBack = 1.
3 Finally, return the ans variable.

Time Complexity
O(N), where N denotes the number of elements of arr.
As every index will be visited at most once, the time complexity will be O(N).

Space Complexity
O(1)Constant space is used.
*/

int maximumProduct(vector<int> &arr, int n){
    
    int ans = INT_MIN;

    int productFromFront = 1, productFromBack = 1;

    for(int i = 0; i < n; i++){
        productFromFront = productFromFront * arr[i];
        productFromBack = productFromBack * arr[n-i-1];

        // Store the maximum of ans, productFromFront and productFromBack in the ans variable.
        ans = max({ans, productFromFront, productFromBack});

        // If any of the products become 0, make them 1 again.
        if(productFromFront == 0){
            productFromFront = 1;
        }
        if(productFromBack == 0){
            productFromBack = 1;
        }
    }

    return ans;
}


/*
Given an array that contains both positive and negative integers. Find and return the product of maximum product subarray
Assumption There is always a positive product possible. ie no array of this form (0, 20,0,0) or (-20)*/

int Max_Product_Subarray(int arr[], int n) {
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(1, min_ending_here * arr[i]);
        }
        else if (arr[i] < 0) {
            int temp = max_ending_here;
            max_ending_here = max(1, min_ending_here * arr[i]);
            min_ending_here = temp * arr[i];
        }
        else {
            max_ending_here = 1;
            min_ending_here = 1;
        }

        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << Max_Product_Subarray(arr, n) << endl;
}
/*
88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 
Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 
Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1;
        m--;
        n--;
        
        while(m >= 0 and n >= 0) {
            if(nums2[n] >= nums1[m]) {
                nums1[k--] = nums2[n--]; 
            } else {
                nums1[k--] = nums1[m--];
            }
        }
        while(n>=0){
            nums1[k--] = nums2[n--];
        }
        
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       for(int i=m;i<m+n;i++) {
            nums1[i]=nums2[i-m];
        }
         int gap;
        if((m+n)%2) {
            gap=(m+n)/2+1;
        }
        else {
            gap=(m+n)/2;
        }
      while(gap>1) {
        //cout<<gap<<endl;
            for(int i=0,j=i+gap;j<m+n;i++,j++) {
                if(nums1[i]>nums1[j]) {
                    swap(nums1[i],nums1[j]);
                }
            }
            if(gap%2) {
                gap=gap/2+1;
            }
            else {
                gap=gap/2;
            }
        }
        for(int i=0,j=i+gap;j<m+n;i++,j++) {
            if(nums1[i]>nums1[j]) {
                swap(nums1[i],nums1[j]);
            }
         }
    }
};
/*
Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Examples:

Example 1:

Input: 
n = 4, arr1[] = [1 4 8 10] 
m = 5, arr2[] = [2 3 9]

Output: 
arr1[] = [1 2 3 4]
arr2[] = [8 9 10]

Explanation:
After merging the two 
non-decreasing arrays, we get, 
1,2,3,4,8,9,10.

Example2:

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]

Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]

Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.
*/

/*
Solution1: Brute Force-

Intuition: We can use a new array of size n+m and put all elements of arr1 and arr2 in it, and sort it. After sorting it, but all the elements in arr1 and arr2.

Approach:

Make an arr3 of size n+m.
Put elements arr1 and arr2 in arr3.
Sort the arr3.
Now first fill the arr1 and then fill remaining elements in arr2. 

Time complexity: O(n*log(n))+O(n)+O(n)
Space Complexity: O(n) 
*/

void merge(int arr1[], int arr2[], int n, int m) {
    int arr3[n+m];
    int k = 0;
    for (int i = 0; i < n; i++) {
      arr3[k++] = arr1[i];
    }
    for (int i = 0; i < m; i++) {
      arr3[k++] = arr2[i];
    }
    sort(arr3,arr3+m+n);
    k = 0;
    for (int i = 0; i < n; i++) {
      arr1[i] = arr3[k++];
    }
    for (int i = 0; i < m; i++) {
      arr2[i] = arr3[k++];
    }

  }


/*
Solution 2: Without using space-

Intuition: We can think of Iterating in arr1 and whenever we encounter an element that is greater than the first element of arr2, just swap it. Now rearrange the arr2 in a sorted manner, after completion of the loop we will get elements of both the arrays in non-decreasing order.

Approach:

Use a for loop in arr1.
Whenever we get any element in arr1 which is greater than the first element of arr2,swap it.
Rearrange arr2.
Repeat the process.

Time complexity: O(n*m)
Space Complexity: O(1) 
*/


void merge(int arr1[], int arr2[], int n, int m) {
  // code here
  int i, k;
  for (i = 0; i < n; i++) {
    // take first element from arr1 
    // compare it with first element of second array
    // if condition match, then swap
    if (arr1[i] > arr2[0]) {
      int temp = arr1[i];
      arr1[i] = arr2[0];
      arr2[0] = temp;
    }

    // then sort the second array
    // put the element in its correct position
    // so that next cycle can swap elements correctly
    int first = arr2[0];
    // insertion sort is used here
    for (k = 1; k < m && arr2[k] < first; k++) {
      arr2[k - 1] = arr2[k];
    }
    arr2[k - 1] = first;
  }
}

/*
Solution 3: Gap method-

Approach:

Initially take the gap as (m+n)/2;
Take as a pointer1 = 0 and pointer2 = gap.
Run a oop from pointer1 &  pointer2 to  m+n and whenever arr[pointer2]<arr[pointer1], just swap those.
After completion of the loop reduce the gap as gap=gap/2.
Repeat the process until gap>0.

Time complexity: O(logn)
Space Complexity: O(1)
*/

void merge(int ar1[], int ar2[], int n, int m) {
  // code here 
  int gap = ceil((float)(n + m) / 2);
  while (gap > 0) {
    int i = 0;
    int j = gap;
    while (j < (n + m)) {
      if (j < n && ar1[i] > ar1[j]) {
        swap(ar1[i], ar1[j]);
      } else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
        swap(ar1[i], ar2[j - n]);
      } else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
        swap(ar2[i - n], ar2[j - n]);
      }
      j++;
      i++;
    }
    if (gap == 1) {
      gap = 0;
    } else {
      gap = ceil((float) gap / 2);
    }
  }
}



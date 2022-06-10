/*1095. Find in Mountain Array

(This problem is an interactive problem.)
You may recall that an array arr is a mountain array if and only if:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.
You cannot access the mountain array directly. You may only access the array using a MountainArray interface:
MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

 
Example 1:
Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.

Example 2:
Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
 
Constraints:
3 <= mountain_arr.length() <= 104
0 <= target <= 109
0 <= mountain_arr.get(index) <= 10^9
*/


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 
 Steps:-

find peak element position
first serach from start to peak element position, if present return position
if(flagL) return mid;
If we not find in step 2, then we will serach from peak to end of array, if present return position
if(flagR) return mid;
If not present
return -1

 The length of arr is 10^4, hence log(N) = 14 and for three binary searches, its 42 , very well below 100.
 
 Time complexity: O(logN)
Space complexity: O(1)
 */

class Solution {
   public:
  int findInMountainArray(int target, MountainArray A) {
        int left = 0, right = A.length() - 1;
        // Find the peak index
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A.get(mid) < A.get(mid + 1)) {
                left = mid + 1;
            } else { 
                right = mid;
            }
        }
        int peak = left;
        
        // Binary search on increasing subarray
        left = 0;
        right = peak;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A.get(mid) < target) {
                left = mid + 1;
            } else if (A.get(mid) > target) { 
                right = mid - 1;
            } else {
                return mid;
            }
        }
        
        // Binary search on decreasing subarray
        left = peak;
        right = A.length() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A.get(mid) < target) {
                right = mid - 1;
            } else if (A.get(mid) > target) { 
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
/*
Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10
 
Constraints:
1 <= nums.length <= 105
0 <= nums[i] <= 105

*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int low = 0,n=nums.size();
      int high = n - 2;
        
      while (low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid]==nums[mid^1]){
          low=mid+1;
        }
        else{
          high=mid-1;
        }
      }
      return nums[low];
    }
};


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low=0;
        int high=n-1;
        
        while(low <= high){ 
            if(low == high)
                return nums[low];
            
            int mid = low + (high-low)/2;
            
            // duplicate element not found in neighbour of start/end
            if((mid==0 && nums[mid]!= nums[mid+1]) || (mid==n-1 && nums[mid]!= nums[mid-1]))
                return nums[mid];
            
            //duplicate element not found in neighbour 
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            
            //duplicate element in right side
            if(nums[mid]==nums[mid+1]){
                if(mid%2 == 0) // even no. of elements in left of mid
                    low = mid+1;
                else
                    high = mid-1;
            }
            
            //duplicate element in right side
            if(nums[mid]==nums[mid-1]){
                if(mid%2 == 0) // even no. of elements in left of mid
                    high = mid-1;
                else
                    low = mid+1;
            }
            
        }
        return 0; // return any int here
    }
}; 


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int low = 0,n=nums.size();
      int high = n - 2;
        
      while (low <= high) {
        int mid = (low + high) / 2;
        if (mid % 2 == 0) {
          if (nums[mid] != nums[mid + 1]) 
           //Checking whether we are in right half
            high = mid - 1; //Shrinking the right half
          else
            low = mid + 1; //Shrinking the left half
        } 
        else { //Checking whether we are in right half
            if (nums[mid] == nums[mid + 1]) 
              high = mid - 1; //Shrinking the right half
            else
              low = mid + 1; //Shrinking the left half
            }
      }
      return nums[low];
    }
};
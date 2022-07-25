/*
1051. Height Checker

A school is trying to take an annual photo of all the students. The students are asked to stand in a 
single file line in non-decreasing order by height. Let this ordering be represented by the integer 
array expected where expected[i] is the expected height of the ith student in line.

You are given an integer array heights representing the current order that the students are standing in. 
Each heights[i] is the height of the ith student in line (0-indexed).
Return the number of indices where heights[i] != expected[i].

 
Example 1:
Input: heights = [1,1,4,2,1,3]
Output: 3

Explanation: 
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.

Example 2:
Input: heights = [5,1,2,3,4]
Output: 5

Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.

Example 3:
Input: heights = [1,2,3,4,5]
Output: 0

Explanation:
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.
 
Constraints:
1 <= heights.length <= 100
1 <= heights[i] <= 100
*/


/*
if you approached this like me and looked at it as a longest non-decreasing subsequence problem, 
then you would only say 4 and 2 are out of place, since 1, 1, 1, 3 is still a non-decreasing height order.

What the question is actually asking, is which elements are out of order compared to the positions if 
every person was ordered correctly. I'll illustrate by example. For example, using the same input as 
above. If every one is in order, we would have sorted = [1, 1, 1, 2, 3, 4] and if we now compare this 
to the original input input = [1, 1, 4, 2, 1, 3], we notice that sorted[i] == input[i] for i = 0, 1, 3 
and hence the remaining elements in indexes 2, 4, 5 are out of place. So the answer is 3.

Solution
Well, the most intuitive solution would be to sort the input and then compare each element.
Using something like Arrays.sort() would give a O(n lg n) solution, but we can actually do better.
Because it is heights we are talking about (which naturally have a limit) and the problem gave us that 
heights is between 1 and 100, we can actually do a bucket/counting sort which only takes 
O(100n) = O(n) time.

The answer first counts up the heights and puts them in a map and then compares them in order to the 
heights in the input array.
*/


class Solution {
public:
    int heightChecker(vector<int>& heights) {
      vector<int>expected = heights;
      int res=0;
      sort(expected.begin(), expected.end());
      for(auto i=0;i<heights.size();++i)
        res += heights[i] != expected[i];
      
      return res;
    }
};



    int heightChecker(vector<int>& heights) {
        // Boundary cases
        if (heights.size()<2)
            return 0;
        
        // The basic idea is to utilize the information regarding the [1,100] interval
        vector<int> map(101,0);
        
        // Record all the values in original array and count its occurences
        for (int h:heights)
            map[h]++;
        
        int res = 0;
        
        // h pointer points to the values in a sorted array
        int h_ptr = 1;
        
        for (int h:heights)
        {
            // Sorted value increases if no such value exists in original array
            while (map[h_ptr]==0)
                h_ptr++;
            
            // If h does not equal h_ptr, it means h is not at right position 
            if (h != h_ptr)
                res++;
            
            // If there are multiple occurences for a single value, keep h_ptr unchanged
            // untill passing all the positions corresponding to this specific value
            map[h_ptr]--;
        }
        
        return res;
    }
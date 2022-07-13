/*
633. Sum of Square Numbers

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 
Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false
 
Constraints:
0 <= c <= 231 - 1
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int start=0,end=sqrt(c);
        
        while(start<=end) {
            long long int sum = start*start + end*end;
            
            if(sum==c) {
                return true;
            }
            else if(sum<c) {
                start++;
            }
            else {
                end--;
            }
        }
        
        return false;
    }
};
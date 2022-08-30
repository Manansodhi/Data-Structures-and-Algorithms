/*
282. Expression Add Operators

Given a string num that contains only digits and an integer target, return all possibilities
to insert the binary operators '+', '-', and/or '*' between the digits of num so that the 
resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.


Example 1:
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

Example 2:
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.

Example 3:
Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 
9191.
 

Constraints:
1 <= num.length <= 10
num consists of only digits.
-231 <= target <= 231 - 1
*/

/**
Time = O(4^n) , n= num.size()
Space = O(n)
**/
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        recursion(ans, num, target, "", 0, 0, 0 );
        return ans;
    }
    
    void recursion(vector<string>& ans, const string& num, const int& target, string expression, int idx, int prevNum, long long curTotal){
        int n = num.size();
        if(idx==n){
            if(curTotal==target){
                ans.push_back(expression);
            }
            return;
        }
        string curNumStr = "";
        long long curNum = 0;
        for(int i = idx; i<n; i++){
            if(i>idx && num[idx]=='0')break;
            curNumStr+=num[i];
            curNum = curNum*10+(num[i]-'0');
            // 2345
            if(idx==0){
                recursion(ans, num, target, expression+curNumStr, i+1, curNum, curTotal+curNum);
            }
            else{
                recursion(ans, num, target, expression+"+"+curNumStr, i+1, curNum, curTotal+curNum);
                recursion(ans, num, target, expression+"-"+curNumStr, i+1, -curNum, curTotal-curNum);
                recursion(ans, num, target, expression+"*"+curNumStr, i+1, prevNum*curNum, curTotal-prevNum+prevNum*curNum);
            }
        }
    }
    
};
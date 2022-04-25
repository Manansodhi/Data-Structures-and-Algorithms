/*
39. Combination Sum
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

Constraints:
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500

*/


using choice = vector<int>;
vector<int> arr = {};

// returning all possible choices to make target sum by using suffix of array [curIndex, ...]
vector<choice> getAllChoices(int curIndex, int target) {
    // base case
    if (target < 0) return {}; // no valid choice
    if (target == 0) return {{}}; // one choice, and you chose nothing
    if (curIndex == arr.size()) return {};

    int curNumber = arr[curIndex];

    vector<choice> ans = getAllChoices(curIndex + 1, target); // curNumber is not used at all

    vector<choice> other = getAllChoices(curIndex, target - curNumber); // using it once
    for (choice c : other) {
        c.push_back(curNumber);
        // now c is a valid choice
        ans.push_back(c);
    }

    return ans;
}

class Solution {

public:
    vector<choice> combinationSum(vector<int>& candidates, int target) {
        arr = candidates;
        return getAllChoices(0, target);
    }
};
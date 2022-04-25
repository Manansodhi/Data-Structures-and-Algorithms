/*
1288. Remove Covered Intervals
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
Return the number of remaining intervals.

Example 1:
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

Example 2:
Input: intervals = [[1,4],[2,3]]
Output: 1
 
Constraints:
1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= li < ri <= 105
All the given intervals are unique.

*/


using interval = vector<int>;

bool comparator(const interval &left, const interval &right){
  if(left[0]==right[0]){
    return left[1]>right[1];
  }
  return left[0]<right[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<interval>& intervals) {
      sort(intervals.begin(), intervals.end(),comparator);
      
      int ans = intervals.size();
      int maxEnd=0;
      for(interval cur:intervals){
        int curEnd=cur[1];
        if(curEnd<=maxEnd){
          ans--;
        }
        maxEnd=max(maxEnd,curEnd);
      }
      return ans;
      
    }
};
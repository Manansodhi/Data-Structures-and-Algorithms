/*
1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts 
where:

horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and 
similarly, and verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical 
cut.Return the maximum area of a piece of cake after you cut at each horizontal and vertical position 
provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return 
this modulo 109 + 7.

 

Example 1:


Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and 
vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
Example 2:


Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and 
vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9
 

Constraints:

2 <= h, w <= 109
1 <= horizontalCuts.length <= min(h - 1, 105)
1 <= verticalCuts.length <= min(w - 1, 105)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
All the elements in horizontalCuts are distinct.
All the elements in verticalCuts are distinct.
*/

class Solution {
public:
  
  static bool comparator(int &a, int &b){
    return a<b;
  }
  
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
      sort(horizontalCuts.begin(), horizontalCuts.end(), comparator);
      sort(verticalCuts.begin(), verticalCuts.end(), comparator);
      
      auto maxVertical=max(verticalCuts[0], w-verticalCuts.back());
   
        for(auto i=0;verticalCuts.size()-1>i;i++){
          maxVertical = max(maxVertical, verticalCuts[i+1]-verticalCuts[i]);
        }
     
      auto maxHorizontal=max(horizontalCuts[0], h-horizontalCuts.back());
      
        for(auto i=0;horizontalCuts.size()-1>i;i++){
          maxHorizontal = max(maxHorizontal, horizontalCuts[i+1]-horizontalCuts[i]);
        }
      
    
      
      // cout<<maxVertical<<endl;
      // cout<<maxHorizontal<<endl;
      
      return (long)maxVertical*maxHorizontal % 1000000007;
    }
};


class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.emplace_back(0);
        vc.emplace_back(0);
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        hc.emplace_back(h);
        vc.emplace_back(w);
        long long res=0;
        long long longesth=0, longestv=0, hn = hc.size(), vn = vc.size();
        for(int i=1; i<hn; i++){
            longesth = max(longesth, 1ll*hc[i]-hc[i-1]*1ll);
        }
        for(int i=1; i<vn; i++){
            longestv = max(longestv, 1ll*vc[i]-vc[i-1]*1ll);
        }
        long long mod = 1e9+7;
        return (1ll*longesth*longestv*1ll)%mod;
    }
};


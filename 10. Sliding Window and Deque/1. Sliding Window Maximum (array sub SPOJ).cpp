#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int>ans;
      int Size = nums.size();
      deque<int>q(k);
      int i;
      //processing first k elements
      for(i=0;i<k;i++){
        while(!q.empty() and nums[i]>nums[q.back()]){
          q.pop_back();
        }
        q.push_back(i);
      }
      
      //processing remaining element
      for(;i<Size;i++){
        ans.push_back(nums[q.front()]);
        
        //removing the elements which are not the part of window(contraction)
        while(!q.empty() and (q.front()<=i-k)){
          q.pop_front();
        }
        
        //removing elements which are not usefull and are in window
        while(!q.empty() and nums[i]>=nums[q.back()]){
          q.pop_back();
        }
        
        //adding new elements(expansionn)
        q.push_back(i);
      }
      ans.push_back(nums[q.front()]);
      return ans;
    }
};



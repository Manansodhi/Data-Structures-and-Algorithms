
class Solution {
public:
  void findSubsets(int idx,vector<int>arr, vector<vector<int>>&ans, vector<int>&ds){
    ans.push_back(ds);
    for(int i=idx;i<arr.size();i++){
      if(i!=idx && arr[i]==arr[i-1])
        continue;
      ds.push_back(arr[i]);
      findSubsets(i+1,arr,ans,ds);
      ds.pop_back();
    }
  }
  
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>>ans;
      vector<int>ds;
      sort(nums.begin(),nums.end());
      findSubsets(0,nums,ans,ds);
      return ans;
    }
}; 
class Solution {
public:
    
    //RECURSION 
//     void findSubsets(int idx,vector<int>arr, vector<vector<int>> &ans, vector<int> &ds){
//         ans.push_back(ds);
//         for(int i=idx;i<arr.size();i++){
//             if(i>idx && arr[i]==arr[i-1])
//                 continue;
//             ds.push_back(arr[i]);
//             findSubsets(i+1,arr,ans,ds);
//             ds.pop_back();
//         }
//     }
    
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>ds;
//         sort(nums.begin(),nums.end());
//         findSubsets(0,nums,ans,ds);
//         return ans;
//     }
    
    //POWER SET  T.C -- O(N*2^(N))
    
     vector<vector<int>> subsets(vector<int>& nums){
         vector<vector<int>>ans;
         int n=nums.size();
         for(int i=0;i<(1<<n);i++){
             vector<int>v;
             for(int j=0;j<n;j++){
                 if((1<<j)&i)
                     v.push_back(nums[j]);
             }
             ans.push_back(v);
         }
         return ans;
     }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=INT_MAX,ele2=INT_MAX,cnt1=0,cnt2=0;
        int n=nums.size();
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(ele1==nums[i])
                cnt1++;
            else if(ele2==nums[i])
                cnt2++;
            else if(cnt1==0){
                ele1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                ele2=nums[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1=cnt2=0;
        
        for(auto x:nums){
            if(ele1==x)
                cnt1++;
            else if(ele2==x)
                cnt2++;
        }
        
        if(cnt1>n/3)
            ans.push_back(ele1);
        if(cnt2>n/3)
            ans.push_back(ele2);
        
        return ans;
        
    }
};
//PRINTING Longest Increasing Subsequence

#include<bits/stdc++.h>

   
 int longestIncreasingSubsequence(int arr[], int n) {
    
      vector<int> dp(n,1), hash(n);
     int maxi=1,lastIdx=0;
     for(int idx=0;idx<=n-1;idx++){ 
         hash[idx] = idx;
       for(int prev=0;prev<=idx-1;prev++){
         if(arr[prev]<arr[idx] && 1+dp[prev]>dp[idx]){
             
           dp[idx] = 1+dp[prev];
             hash[idx] = prev;
         }
       }
       if(dp[idx] > maxi){
           maxi = dp[idx];
           lastIdx = idx;
       }
     }
    vector<int>temp;
     temp.push_back(arr[lastIdx]);
     while(hash[lastIdx] != lastIdx){
         lastIdx = hash[lastIdx];
         temp.push_back(arr[lastIdx]);
     }
     reverse(temp.begin(), temp.end());
     for(auto it:temp)
         cout<<it<<" ";
     cout<<endl;
     return maxi;
    }

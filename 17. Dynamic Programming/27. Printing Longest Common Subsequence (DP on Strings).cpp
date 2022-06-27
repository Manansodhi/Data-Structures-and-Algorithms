//Printing Longest Common Subsequence

//Code for returning longest length of common subsequence
int longestCommonSubsequence(string s1, string s2) {
      int n = s1.size();
      int m = s2.size();
      vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 
        
        //base case
        for(int idx1=0;idx1<=n;idx1++)
            dp[idx1][0]=0;
        for(int idx2=0;idx2<=m;idx2++)
            dp[0][idx2]=0;
             
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(s1[idx1-1] == s2[idx2-1]) 
                     dp[idx1][idx2] = (1+dp[idx1-1][idx2-1]);
                else 
                    dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
            }
        }
        

        for(int i=0;i<=n;i++){ 
        	for(int j=0;j<=m;j++){ 
        		cout<<dp[i][j]<<" "; 
        	} 
        	cout<<endl; 
        }
        /*OUTPUT THIS NESTED LOOP
	        0 0 0 0 0 0
			0 0 0 0 0 0
			0 1 1 1 1 1
			0 1 1 1 1 1
			0 1 2 2 2 2
			0 1 2 2 3 3

		*/

      //Included Extra code
        int len = dp[n][m];//len of lcs
        string ans= "";
        for(int i=0i<len;i++){
        	ans+='$';  //adding dummmy to string of len 3 same as len of lcs 
        }

        int index=len-1;
        // index ye voh point h jha per lcs ko dalna shuru karege last se becoz dp[n][m] s 
        //start kar rahe  hum

        int idx1=n, idx2=m;
        while(idx1>0  && idx2>0){
        	if(s1[idx1-1] == s2[idx2-1]){
        		ans[index] = s[idx1-1];
        		index--;
        		idx1--,idx2;
        	}
        	else if(dp[idx1-1][idx2] > dp[idx1][idx2]){
        		idx1--;
        	}
        	else
        		idx2--;
        }
        cout<<ans;

    }
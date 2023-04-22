    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        
        if(arr[n-1]<=sum)
          dp[n-1][arr[n-1]] =1;
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=1;j<=sum;j++)
            {
                dp[i][j] = dp[i+1][j];
                
                if(j>=arr[i])
                     dp[i][j] = dp[i][j] || dp[i+1][j-arr[i]];
            }
        }
       
        
        return dp[0][sum];
    }

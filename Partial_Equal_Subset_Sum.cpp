    bool solve(int n, int arr[],int w)
    {
        vector<vector<int>> dp(n+1,vector<int>(w+1,0));
        
        for(int i=0;i<=n;i++)
          dp[i][0] = 1;
          
          
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(arr[i-1] <= j)
                  dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                  dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][w];
    }


    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for(int i=0;i<N;i++)
         sum += arr[i];
         
        if((sum&1) != 0)
          return 0;
        
        return solve(N,arr,sum/2);
    }

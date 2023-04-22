    long long int count(int coins[], int n, int sum) {

       vector<long long int> dp(sum+1,0);
     
       
       
       for(int i=0;i<=sum;i++)
        {
            
                if(i%coins[0] == 0)
                {
                    dp[i] = 1;
                }
            
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                long long int notTake = dp[j];
                long long int take = 0;
                
                if(coins[i] <= j)
                {
                    take = dp[j-coins[i]];
                }
                
                dp[j] = take + notTake;
            
            }
        }
      
        return dp[sum];
    }

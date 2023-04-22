   int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        //mp[x] will keep track of number of LIS of length x
        unordered_map<int,int> mp;
        vector<int> dp(n,1);

        int len=1;
        mp[1] = n;
        for(int i=1;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev] < nums[i]  )
                {
                    if(dp[prev]+1 > dp[i])
                        dp[i] = dp[prev] + 1;

                    if(dp[prev]+1 == 5)
                      cout<<prev<<" ** "<<i<<endl;
                    mp[dp[prev]+1]++;
                }
            }

            
            if(dp[i] >= len)
            {
                len = dp[i];
            }
        }     

        return mp[len];  
    }

	void leftToRight(vector<int> &nums, vector<int> &dp)
	{
	    int n = nums.size();
        dp[0] = 1;
        for(int i=1;i<n;i++)
        {
            dp[i] = 1;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev] < nums[i] && dp[prev]+1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                }
            }
            
        }
	}
	
	
	void rightToLeft(vector<int> &nums, vector<int> &dp)
	{
	    int n = nums.size();
        dp[n-1] = 1;
        for(int i=n-2;i>=0;i--)
        {
            dp[i] = 1;
            for(int prev=n-1;prev>i;prev--)
            {
                if(nums[prev] < nums[i] && dp[prev]+1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                }
            }
            
        }
	}
	int LongestBitonicSequence(vector<int>nums)
	{
	    int   n = nums.size();
	    vector<int> dp1(n,0), dp2(n,0);
	    
	    leftToRight(nums,dp1);
	    rightToLeft(nums,dp2);
	    int ans = 0;
	    for(int i=0;i<n;i++)
	    {
	        ans = max(ans, dp1[i] + dp2[i]);
	    }
	    return ans-1;
	}

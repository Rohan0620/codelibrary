    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        
        for(int i=1;i<n;i++)
        {
            lis[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                {
                    lis[i] = max(lis[i] , lis[j] + 1);
                }
            }
        }
        
        return *max_element(lis.begin(), lis.end());
    }

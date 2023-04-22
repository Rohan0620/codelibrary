    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> val;
        
        for(int i=0;i<n;i++)
        {
            double x = (arr[i].value*1.0)/(arr[i].weight*1.0);
            val.push_back({x,arr[i].weight});
        }
        
        double amount = 0;
        
        sort(val.begin(), val.end(), greater<>());
        
        for(int i=0;i<n&&W>0;i++)
        {
            if(val[i].second <= W)
            {
                amount += (val[i].second*val[i].first);
                W-=val[i].second;
            }else
            {
                amount+=(W*val[i].first);
                W=0;
            }
        }
        
        return amount;
    }

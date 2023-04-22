int maxProfit(vector<int>&price){
    int n= price.size();
    vector<int> profit(n,0);
    
    int max_val = price[n-1];
    
    for(int i=n-2;i>=0;i--)
    {
        if(price[i] > max_val)
          max_val = price[i];
          
        profit[i] = max(profit[i+1], max_val - price[i]);
    }
    
    int min_val = price[0];
    
    for(int i=1;i<n;i++)
    {
        if(price[i] < min_val)
          min_val = price[i];
          
        profit[i] = max(profit[i-1], profit[i] + price[i] - min_val);
    }
    
    return profit[n-1];
}

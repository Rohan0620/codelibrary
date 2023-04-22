   string longestCommonPrefix(vector<string>& arr) {
         int N =arr.size();
         int len = 0;
        
        for(int i=0;i<arr[0].size();i++)
        {
            string temp = arr[0].substr(0,i+1);
            int flag =1;
            for(int j=1;j<N;j++)
            {
                if(temp.size() > arr[j].size())
                {
                    flag =0;
                    break;
                }
               string cur = arr[j].substr(0,i+1);
               
               if(cur != temp)
               {
                   flag = 0;
                   break;
               }
            }
            
            if(flag)
              len = max(len , i+1);
        }
        
        if(len == 0)
          return "";
        return arr[0].substr(0,len);        
    }

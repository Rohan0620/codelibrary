class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                  q.push({i,j});
                if(grid[i][j] == 1)
                  count++;
            }
        }
        
  
        int tim = -1, cnt = 0;
        
        while(!q.empty() && cnt!=count)
        {
            int size = q.size();
            tim++;
            
            for(int i=0;i<size;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
               // cout<<x<<" "<<y<<" " <<cnt<<endl;
                q.pop();
                if(grid[x][y] == 2 && tim!=0)
                  continue;
                if(grid[x][y] == 1)
                cnt++;
                grid[x][y] = 2;
                
                if(x+1 < n && grid[x+1][y] == 1)
                  q.push({x+1,y});
                  
                if(y+1 < m && grid[x][y+1] == 1)
                 q.push({x,y+1});
                 
                if(x>0 && grid[x-1][y] == 1)
                 q.push({x-1,y});
                 
                if(y>0 && grid[x][y-1] == 1)
                 q.push({x,y-1});
            
               
            }
        }
     
        if(cnt != count)
          return -1;
          
        return tim;
    }
};

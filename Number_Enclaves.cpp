class Solution {
int dx[4] = {0,0,-1,1};
  int dy[4] = {-1,1,0,0};
  void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j, int n, int m)
  {
      if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j] == 0)
        return;
        
      visited[i][j] = 1;
      grid[i][j] = 0;
      
      for(int k=0;k<4;k++)
      {
          
          dfs(grid, visited, i+dx[k] , j+dy[k], n, m);
      }
      
  }
  
  
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 1)
              dfs(grid, visited, i, 0, n, m);
              
            if(grid[i][m-1] == 1)
             dfs(grid,visited,i,m-1,n, m);
        }
        
        
        for(int i=0;i<m;i++)
        {
            if(grid[0][i] == 1)
              dfs(grid,visited, 0, i, n, m);
              
            if(grid[n-1][i] == 1)
              dfs(grid, visited, n-1, i, n ,m);
        }
        
        
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                 cnt++;
            }
        }
        
        return cnt;
    }
};

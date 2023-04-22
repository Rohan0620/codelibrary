class Solution {
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int,int>> &vec, int row0, int col0)
    {
        visited[row][col] = 1;
       vec.push_back({row-row0, col-col0});
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row+dx[i];
            int ncol = col + dy[i];
            
            if(nrow>=0 && ncol>=0 && nrow<n && ncol <m && grid[nrow][ncol] && !visited[nrow][ncol])
            {
                dfs(nrow,ncol,grid,visited,vec,row0,col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,visited,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};

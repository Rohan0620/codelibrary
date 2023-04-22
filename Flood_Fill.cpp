    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void dfs(vector<vector<int>>& image, vector<vector<int>>& v,int n, int m, int i, int j, int newColor,int ini)
    {
        if(i<0 || j<0 || i>=n || j>=m || v[i][j])
          return;
         v[i][j] = 1;  
        if(image[i][j] == ini)
        image[i][j] = newColor;
        else
        return;
        
        for(int k=0;k<4;k++)
         dfs(image,v,n,m,i+dx[k],j+dy[k],newColor,ini);
       
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> v(n,vector<int> (m,0));
        
        dfs(image,v,n,m,sr,sc,newColor, image[sr][sc]);
        
        
        return image;
    }

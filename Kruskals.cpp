class DisjointSet
{
    private : 
    vector<int> parent, rank;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }
    
    int findParent(int node)
    {
        if(parent[node] == node)
          return node;
          
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(pu == pv)
          return ;
          
        if(rank[pu] < rank[pv])
        {
            parent[pu] = pv;
            
        }else if(rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
             parent[pv] = pu;
             rank[pu]++;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
          vector<pair<int,pair<int,int>>> edges;
          for(int i=0;i<V;i++)
          {
              for(auto it:adj[i])
              {
                  int u = i;
                  int v = it[0];
                  int wt = it[1];
                  
                  edges.push_back({wt,{u,v}});
              }
          }
          
          sort(edges.begin(), edges.end());
          int ans = 0;
          DisjointSet ds(V);
          for(auto x:edges)
          {
              int u = x.second.first;
              int v = x.second.second;
              int wt = x.first;
              
              if(ds.findParent(u) != ds.findParent(v))
              {
                  ans += wt;
                  ds.unionByRank(u,v);
              }
          }
          
          return ans;
    }
};

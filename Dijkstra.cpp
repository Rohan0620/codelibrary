class Solution
{
    typedef pair<int, int> pi;
	public:
  	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> pq;
        
        vector<int> dist(V,1e9);
        
        dist[S] = 0;
        
        pq.insert({0,S});
        
        while(!pq.empty())
        {
            auto fir = *(pq.begin());
            int node = fir.second;
            int d = fir.first;
            pq.erase({d,node});
            for(auto x:adj[node])
            {
                int newNode = x[0];
                int newWt = x[1];
                if(newWt + d < dist[newNode])
                {
                    dist[newNode] = newWt + d;
                    pq.insert({d+newWt,newNode});
                }
            }
        }
        
        return dist;
    }
};

//User function Template for C++

//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<vector<int>>adjlist,vector<bool>& visited)
    {
        visited[node]=true;
        
        for(auto x:adjlist[node])
        {
            if(!visited[x])
            {
                dfs(x,adjlist,visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool>visited(V,false);
        vector<vector<int>>adjlist(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 and i!=j)
                {
                    adjlist[i].push_back(j);
                }
            }
        }
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,adjlist,visited);
            }
        }
        
        return count;
    }
};
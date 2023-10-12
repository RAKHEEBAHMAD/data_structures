class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,vector<int> adj[],vector<bool>& visited,int parent)
    {
        visited[node]=true;
        for(auto x:adj[node])
        {
            if(!visited[x])
            {
                if (dfs(x, adj, visited, node)) {
                return true;
                }
            }else{
                if(x!=parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        for (int i = 0; i < V; ++i) {
        if (!visited[i] and dfs(i, adj, visited, -1)) {
            return true;
        }
    }
    return false;
    }
};
#include<bits/stdc++.h>
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int> adj[],vector<bool>& visited,vector<int>& res)
    {
        visited[node] = true;
        res.push_back(node);
        
        for(auto x:adj[node])
        {
            if(!visited[x])
            {
                dfs(x,adj,visited,res);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        vector<int>res;
        int start=0;
        dfs(start,adj,visited,res);
        return res;
    }
};
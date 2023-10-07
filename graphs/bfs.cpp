class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<int>res;
        queue<int>q;
         q.push(0);
         visited[0]=true;
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            
            res.push_back(current);
            
            for(auto x:adj[current])
            {
                if(!visited[x])
                {
                    q.push(x);
                    visited[x]=true;
                }
            }
            
        }
        return res;
    }
};
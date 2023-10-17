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


/*if confusion refer https://www.geeksforgeeks.org/detect-cycle-undirected-graph/ 

 here we detecting cycle if vertex is already visited and not equal to the parent

 here why we are saying like not equal to parent i.e in undirected graph

 1---2
 \   /
   3

in the above cycle

adjacency matrix is 

1 -> 2,3
2-> 1,3
3-> 1,2

in the above !visited[1] is true when we are in node 2 and we can't consider it as a loop 
1->2 and 2->1 is not loop bro..!! and that's why we are saying that only if not equal to parent

*/


/*---------------------------BFS-----------------------------------------*/
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int src,vector<int>& vis,vector<int> adj[])
    {
        queue<pair<int,int>>q;
        q.push({src,-1});
        vis[src]=1;
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto x:adj[node])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    q.push({x,node});
                    
                }else{
                    if(x!=parent)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(bfs(i,vis,adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
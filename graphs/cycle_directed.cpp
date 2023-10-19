class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> adj[],vector<int>& visited,vector<int>& pathvis)
    {
        visited[node]=1;
        pathvis[node]=1;
        for(auto x:adj[node])
        {
            if(!visited[x])
            {
                if(dfs(x, adj, visited, pathvis))
                {
                    return true;
                }
            }else{
                if(pathvis[x])
                {
                    return true;
                }
            }
        }
        pathvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V,false);
        vector<int>pathvis(V,false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i] and dfs(i, adj, visited, pathvis)) {
                    return true;
                }
        }
        return false;
    }
};



/* dfs with one vertex */
class Solution {
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0); // 0: not visited, 1: visited, 2: currently on the stack

        for (int i = 0; i < V; ++i) {
            if (visited[i] == 0 && isCyclicUtil(i, adj, visited)) {
                return true;
            }
        }

        return false;
    }

    bool isCyclicUtil(int node, vector<int> adj[], vector<int>& visited) {
        visited[node] = 2; // Mark as currently on the stack

        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 2) {
                return true; // Found a cycle
            } else if (visited[neighbor] == 0 && isCyclicUtil(neighbor, adj, visited)) {
                return true;
            }
        }

        visited[node] = 1; // Mark as visited and not part of a cycle
        return false;
    }
};


/*----------------------------BFS(TOPO SORT)---------------------------*/
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>in(V,0);
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                in[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x:adj[node])
            {
                in[x]--;
                if(in[x]==0)
                {
                    q.push(x);
                }
            }
        }
        if(ans.size()==V) return false;
        return true;
    }
};
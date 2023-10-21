/*-----------------DFS--------------------------*/
class Solution {
public:
    bool dfs(int node,vector<int>& color,vector<int>adj[])
    {
        for(auto x:adj[node])
        {
            if(color[x]==-1)
            {
                color[x]=!color[node];
                if(dfs(x,color,adj)==false)
                {
                    return false;
                }
            }else if(color[x]==color[node])
            {
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    bool res=false;
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	             if(dfs(i,color,adj)==false)
	             {
	                 return false;
	             }
	        }
	    }
	    return true;
	}
};

/*--------------------BFS----------------------------------*/

class Solution {
public:
    bool bfs(int src,vector<int>& vis,vector<int>adj[])
    {
        queue<int>q;
        q.push(src);
        vis[src]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto x:adj[node])
            {
                if(vis[x]==-1)
                {
                    vis[x]=!vis[node];
                    q.push(x);
                }else if(vis[node]==vis[x]){
                        return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>vis(V,-1);
	    bool res=false;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==-1)
	        {
	             if(bfs(i,vis,adj)==false)
	             {
	                 return false;
	             }
	        }
	    }
	    return true;
	}
};

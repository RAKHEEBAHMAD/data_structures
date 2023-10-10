
// https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool bfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid )
    {
        int n=grid.size();
        int m= grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==3)
                {
                    grid[nrow][ncol]=1;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==2)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int row=-1,col=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    row=i;
                    col=j;
                }
            }
        }
        
        return bfs(row,col,vis,grid);
        
    }
};
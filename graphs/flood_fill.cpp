/*-----------------------------BFS-------------------------------*/
class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& image,int newcolor)
    {
        int n = image.size();
        int m = image[0].size();
        int val = image[row][col];
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
           
                for(int drow=-1;drow<=1;drow++)
                {
                    int nrow = row+drow;
                    int ncol = col;
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and image[nrow][ncol]==val)
                    {
                        image[nrow][ncol]=newcolor;
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
                
                for(int dcol=-1;dcol<=1;dcol++)
                {
                    int nrow = row;
                    int ncol = col+dcol;
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and image[nrow][ncol]==val)
                    {
                        image[nrow][ncol]=newcolor;
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            
            
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        bfs(sr,sc,vis,image,newColor);
        return image;
    }
};

/*-----------------------------DFS-------------------------------*/

class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& image,int newc,int intial)
    {
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int n=image.size();
        int m=image[row].size();
        
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 and nrow<n and ncol<m and ncol>=0 and !vis[nrow][ncol] and image[nrow][ncol]==intial)
            {
                image[nrow][ncol]=newc;
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,vis,image,newc,intial);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int intial=image[sr][sc];
        image[sr][sc]=newColor;
        dfs(sr,sc,vis,image,newColor,intial);
        return image;
    }
};


/* 

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.

*/
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& mat, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0; // Check for empty matrix
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        // Mark 'O's connected to boundaries as visited
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 1) {
                dfs(i, 0, vis, mat, delrow, delcol);
            }
            if (mat[i][m - 1] == 1) {
                dfs(i, m - 1, vis, mat, delrow, delcol);
            }
        }
        for (int i = 0; i < m; i++) {
            if (mat[0][i] == 1) {
                dfs(0, i, vis, mat, delrow, delcol);
            }
            if (mat[n - 1][i] == 1) {
                dfs(n - 1, i, vis, mat, delrow, delcol);
            }
        }
        int count=0;
        // Change unvisited 'O's to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};
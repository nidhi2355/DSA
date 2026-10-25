class Solution {
public:
    int dx[4]= {-1, 0, 1, 0};
    int dy[4]= {0, 1, 0, -1};
    int m, n;

    int closedIsland(vector<vector<int>>& grid) {
        m= grid.size(), n= grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            if(grid[i][0] == 0 and !vis[i][0]){
                dfs(grid, i, 0, vis);
            }
            if(grid[i][n-1] == 0 and !vis[i][n-1]){
                dfs(grid, i, n-1, vis);
            }
        }

        for(int j=0; j<n; j++){
            if(grid[0][j] == 0 and !vis[0][j]){
                dfs(grid, 0, j, vis);
            }
            if(grid[m-1][j] == 0 and !vis[m-1][j]){
                dfs(grid, m-1, j, vis);
            }
        }

        int cnt=0;

        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(grid[i][j]==0 and !vis[i][j]){
                    dfs(grid, i, j, vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }

    void dfs(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &vis){
        vis[row][col]=1;

        for(int i=0; i<4; i++){
            int nr= row+ dx[i];
            int nc= col+ dy[i];

            if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc] and grid[nr][nc]==0){
                dfs(grid, nr, nc, vis);
            }
        }
    }
};
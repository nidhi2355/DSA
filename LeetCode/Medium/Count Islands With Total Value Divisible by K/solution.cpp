class Solution {
public:
    int m, n;
    int dx[4] = {-1,0, 1, 0};
    int dy[4]= {0, 1, 0, -1};

    int countIslands(vector<vector<int>>& grid, int k) {
        m= grid.size(), n= grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int ans=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] and grid[i][j]!=0){
                    long long val=0;
                    dfs(i, j, grid, vis, val);
                    if(val%k == 0) ans++;
                }
            }
        }

        return ans;
    }

    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, long long &val){
        val+= 1LL*grid[row][col];
        vis[row][col]=1;

        for(int i=0; i<4; i++){
            int nr= row+ dx[i], nc= col+ dy[i];

            if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc] and grid[nr][nc]!= 0){
                dfs(nr, nc, grid, vis, val);
            }
        }
    }
};
class Solution {
public:
int m, n;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m= obstacleGrid.size(), n= obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1 or obstacleGrid[m-1][n-1]==1) return 0;

        vector<vector<int>> vis(m, vector<int>(n, -1));

        int ans= dfs(0, 0, obstacleGrid, vis);

        return ans;
    }

    int dfs(int row, int col, vector<vector<int>> &obstacleGrid, vector<vector<int>> &vis){
        if(row>= m or col>=n or row<0 or col<0) return 0;

        if(row==m-1 and col==n-1){
            return 1;
        }

        if(vis[row][col]!= -1) {
            return vis[row][col];
        }

        if(obstacleGrid[row][col]==1){
            return vis[row][col]=0;
        }

        int down= dfs(row+1, col, obstacleGrid, vis);
        int right= dfs(row, col+1, obstacleGrid, vis);

        return vis[row][col]= down+ right;
    }
};
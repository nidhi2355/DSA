class Solution {
public:
    int ans=INT_MAX;
    int m, n;

    int minCost(vector<vector<int>>& grid) {
        m= grid.size(), n= grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024, -1)));

        return dfs(0, 0, grid, 0, dp);
    }

    int dfs(int row, int col, vector<vector<int>> &grid, int curr, vector<vector<vector<int>>> &dp){
        curr^= grid[row][col];

        if(row==m-1 and col==n-1){
            return curr;
        }

        if(dp[row][col][curr]!= -1) return dp[row][col][curr];

        int res= INT_MAX;

        if(row<m-1) res= min(res, dfs(row+1, col, grid, curr, dp));
        if(col<n-1) res= min(res, dfs(row, col+1, grid, curr, dp));

        return dp[row][col][curr]= res;
    }
};
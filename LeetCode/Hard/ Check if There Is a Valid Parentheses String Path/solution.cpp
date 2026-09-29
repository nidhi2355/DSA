class Solution {
public:
    int n, m;
    bool hasValidPath(vector<vector<char>>& grid) {
        m= grid.size(), n= grid[0].size();
        if(m==0 or n==0) return false;
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n,vector<int>(m+n,-1)));
        if(grid[0][0]==')' or grid[m-1][n-1]=='(') return false;
        return checkPath(grid, m-1, n-1, 0, dp);
    }
private:
    bool checkPath(vector<vector<char>> &grid, int row, int col, int curr, vector<vector<vector<int>>> &dp){
        if(row<0 or col<0) return false;
        curr+= (grid[row][col]=='(')?-1:1;
        if(curr<0) return false;
        if(row==0 and col==0) return curr==0;
        if(dp[row][col][curr]!=-1) return dp[row][col][curr];
        bool res= checkPath(grid, row-1, col, curr, dp) or checkPath(grid, row, col-1, curr, dp);
        return dp[row][col][curr]= res;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size(), n= grid[0].size();

        int cnt=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    bfs(grid, i, j);
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]=='2') grid[i][j]='1';
            }
        }

        return cnt;
    }

    void bfs(vector<vector<char>> &grid, int row, int col){
        int m= grid.size(), n= grid[0].size();
        int dx[4]= {-1, 0, 1, 0};
        int dy[4]= {0, 1,0,-1};

        grid[row][col]= '2';

        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int i= q.front().first, j= q.front().second;
            q.pop();

            for(int k=0; k<4; k++){
                int nr= i+ dx[k], nc= j+dy[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1'){
                    grid[nr][nc]='2';
                    q.push({nr,nc});
                }
            }
        }
    }
};
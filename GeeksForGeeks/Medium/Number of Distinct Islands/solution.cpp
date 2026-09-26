class Solution {
  public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        int m= grid.size(), n= grid[0].size();
        
        set<vector<pair<int, int>>> st;
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] and grid[i][j]=='L'){
                    bfs(grid, i, j, vis, st);
                }
            }
        }
        
        return (int) st.size();
    }
    
    void bfs(vector<vector<char>> &grid, int row, int col, vector<vector<int>> &vis, set<vector<pair<int, int>>> &st){
        int m= grid.size();
        int n= grid[0].size();
        
        queue<pair<int, int>> q;
        vector<pair<int, int>> temp;
        
        q.push({row, col});
        
        int dx[4]= {-1, 0, 1, 0};
        int dy[4]= {0, 1, 0, -1};
        
        while(!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            
            q.pop();
            
            vis[r][c]=1;
            
            temp.push_back({r-row, c-col});
            
            for(int i=0; i<4; i++){
                int nr= r+ dx[i];
                int nc= c+ dy[i];
                
                if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc] and grid[nr][nc]=='L'){
                    q.push({nr,nc});
                }
            }
            
        }
        
        st.insert(temp);
    }
};

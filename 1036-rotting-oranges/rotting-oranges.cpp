class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();

        int cntfresh= 0;
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) cntfresh++;
                else if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }

        int time=0;
        int dx[4]={-1, 0, 1, 0};
        int dy[4]={0, 1, 0, -1};

        while(!q.empty()){
            int s=q.size();

            for(int i=0; i<s; i++){
                int row= q.front().first, col= q.front().second;

                q.pop();

                for(int j=0; j<4; j++){
                    int nr= row+ dx[j], nc=col+ dy[j];

                    if(nr>=0 and nr<m and nc>=0 and nc<n and grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        cntfresh--;
                        q.push({nr, nc});
                    }
                }
            }

            if(!q.empty()) time++;
        }

        return cntfresh==0? time:-1;
    }
};
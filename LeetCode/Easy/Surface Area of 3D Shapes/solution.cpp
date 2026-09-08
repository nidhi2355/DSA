class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n= grid.size();

        int ans= 0;

        int dx[4]= {-1, 0, 1, 0};
        int dy[4]= {0, 1, 0, -1};
        int cnt=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<4; k++){
                    int nr= i+ dx[k], nc= j+dy[k];

                    if(nr>=0 and nr<n and nc>=0 and nc<n) ans+= abs(grid[i][j]- grid[nr][nc]);
                }

                if(grid[i][j]==0) cnt++;
            }
        }

        ans/=2;

        ans+= 2*(n*n);

        ans-= 2*cnt;

        for(int i=0; i<n; i++){
            ans+= grid[i][0];
            ans+= grid[i][n-1];
            ans+= grid[0][i];
            ans+= grid[n-1][i];
        }

        return ans;
    }
};
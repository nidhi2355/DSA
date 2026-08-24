#define p pair<int, pair<int, int>>

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();

        int dx[4]= {-1, 0, 1, 0};
        int dy[4]= {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int> (n, INT_MAX));

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0]= grid[0][0];

        while(!pq.empty()){

            int row= pq.top().second.first;
            int col= pq.top().second.second;
            int t= pq.top().first;

            if(row==n-1 and col==n-1) return t;

            pq.pop();

            for(int i=0; i<4; i++){
                int nr= row+ dx[i], nc= col+ dy[i];

                if(nr>=0 and nr<n and nc>=0 and nc<n){
                    int time= max(t, grid[nr][nc]);
                    if(vis[nr][nc]> time){
                        vis[nr][nc]= time;
                        pq.push({time, {nr, nc}});
                    }
                }
            }
        }

        return n-1;
    }
};
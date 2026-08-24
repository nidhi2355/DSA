class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m= heights.size(), n= heights[0].size();

        vector<vector<int>> vis(m, vector<int> (n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int dx[4]= {-1, 0, 1, 0};
        int dy[4]= {0, 1, 0, -1};

        vis[0][0]=0;
        pq.push({0, {0, 0}});  // {effort, {row, col} }

        while(!pq.empty()){
            int effort= pq.top().first;
            int row= pq.top().second.first;
            int col= pq.top().second.second;

            pq.pop();

            if(row==m-1 and col==n-1) return effort;

            for(int i=0; i<4; i++){
                int nr= row+ dx[i], nc= col+ dy[i];

                if(nr>=0 and nr<m and nc>=0 and nc<n){
                    int newe= max(effort, abs(heights[nr][nc]- heights[row][col]));
                    if(vis[nr][nc]> newe){
                        vis[nr][nc]= newe;
                        pq.push({newe, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};
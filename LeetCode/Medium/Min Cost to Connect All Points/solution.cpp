class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        int cost=0;

        set<pair<int, int>> vis;

        vis.insert({points[0][0], points[0][1]});

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(int i=1; i<n; i++){
            int dist= abs(points[0][0]- points[i][0])+ abs(points[0][1]- points[i][1]);

            pq.push({dist, {points[i][0], points[i][1]}});
        }

        while(!pq.empty()){
            int d= pq.top().first;
            int x= pq.top().second.first;
            int y= pq.top().second.second;

            pq.pop();

            if(vis.count({x, y})) continue;

            vis.insert({x, y});
            cost+= d;

            for(int i=0; i<n; i++){
                if(x==points[i][0] and y==points[i][1]) continue;

                int dist= abs(x- points[i][0])+ abs(y- points[i][1]);

                pq.push({dist, {points[i][0], points[i][1]}});
            }
        }

        return cost;
    }
};
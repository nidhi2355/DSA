class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});

        while(!q.empty()){
            int node= q.top().second;
            int distance= q.top().first;

            q.pop();

            if(dist[node]< distance) continue;

            for(auto &it: adj[node]){
                int curr= it.first;
                int d= it.second;

                if(distance+d< dist[curr]){
                    dist[curr]= distance+d;
                    q.push({dist[curr], curr});
                }
            }
        }

        int maxd= INT_MIN;

        for(int i=1; i<=n; i++){
            if(dist[i]==INT_MAX) return -1;
            maxd= max(maxd, dist[i]);
        }

        return maxd;
    }
};
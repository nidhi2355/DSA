class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const int INF = 1e9 + 7;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d > dist[u][cnt]) continue;
            if (u == n - 1) return d;

            for (const auto& [v, w] : adj[u]) {
                int next_cnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (next_cnt <= k && d + w < dist[v][next_cnt]) {
                    dist[v][next_cnt] = d + w;
                    pq.push({dist[v][next_cnt], v, next_cnt});
                }
            }
        }

        return -1;
    }
};
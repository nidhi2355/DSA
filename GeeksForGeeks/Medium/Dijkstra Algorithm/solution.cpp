class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src]= 0;
        
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto &it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, src});
        
        while(!pq.empty()){
            int node= pq.top().second;
            int cost= pq.top().first;
            
            pq.pop();
            if(cost > dist[node]) continue;
            
            for(auto &it: adj[node]){
                if(cost+ it.second < dist[it.first]){
                    dist[it.first]= cost+ it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        
        return dist;
    }
};
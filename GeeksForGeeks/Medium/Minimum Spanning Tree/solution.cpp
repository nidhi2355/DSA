class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto &it: edges){
            int u= it[0], v= it[1], w= it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> vis(V, 0);
        
        int cost=0;
        
        vis[0]=1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto &it: adj[0]){
            pq.push({it.second, it.first});
        }
        
        while(!pq.empty()){
            int w= pq.top().first;
            int node= pq.top().second;
            
            pq.pop();
            
            if(vis[node]) continue;
            
            vis[node]=1;
            cost+= w;
            
            for(auto it: adj[node]){
                pq.push({it.second, it.first});
            }
        }
        
        return cost;
    }
};
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        
        vector<int> vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                vis[i]=1;
                if(bfs(i, adj, vis)) return true;
            }
        }
        
        return false;
        
    }
    
    bool bfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        queue<pair<int, int>> q;
        
        q.push({node, -1});
        
        while(!q.empty()){
            int curr=q.front().first;
            int parent= q.front().second;
            
            q.pop();
            
            for(auto it: adj[curr]){
                if(vis[it]){
                    if(it==parent) continue;
                    else return true;
                }
                else{
                    vis[it]=1;
                    q.push({it, curr});
                }
            }
        }
        
        return false;
    }
};
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        vector<int> ans;
        
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return ans;
    }
};
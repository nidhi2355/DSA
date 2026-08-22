class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();

        vector<int> vis(n, -1);

        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(!bfs(i, vis, graph)) return false;
            }
        }

        return true;
    }

    bool bfs(int node, vector<int> &vis, vector<vector<int>> &graph){
        vis[node]=0;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int curr= q.front();
            q.pop();

            for(auto it: graph[curr]){
                if(vis[it]==-1){
                    vis[it]= !vis[curr];
                    q.push(it);
                }

                else if(vis[it]==vis[curr]) return false;
            }
        }

        return true;
    }
};
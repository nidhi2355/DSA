class Solution {
public:
int time=1;

    void dfs(int node, int parent, vector<int> &tin, vector<int> &low, const vector<vector<int>> &adj, vector<vector<int>> &bridges){
        tin[node]= low[node]= time++;

        for(auto &it: adj[node]){
            if(it==parent) continue;

            if(tin[it] != 0){
                low[node]= min(low[node], tin[it]);
            }
            else{
                dfs(it, node, tin, low, adj, bridges);
                
                low[node]= min(low[node], low[it]);

                if(low[it] > tin[node]){
                    bridges.push_back({node, it});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto &it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> bridges;

        dfs(0, -1, tin, low, adj, bridges);

        return bridges;
    }
};
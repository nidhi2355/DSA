class Solution {
public:
    int countSCC(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<vector<int>> adjT(V);

        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adjT[e[1]].push_back(e[0]);
        }

        // Step 1: Iterative DFS to get finish order
        vector<bool> vis(V, false);
        stack<int> order;

        for (int i = 0; i < V; ++i) {
            if (vis[i]) continue;

            // dfs_stack stores pair: {current_node, next_neighbor_index_to_visit}
            stack<pair<int, int>> dfs_st;
            dfs_st.push({i, 0});
            vis[i] = true;

            while (!dfs_st.empty()) {
                auto& [u, idx] = dfs_st.top();

                if (idx < (int)adj[u].size()) {
                    int v = adj[u][idx++];
                    if (!vis[v]) {
                        vis[v] = true;
                        dfs_st.push({v, 0});
                    }
                } else {
                    order.push(u);
                    dfs_st.pop();
                }
            }
        }

        // Step 2 & 3: Traverse transposed graph in order of finish times
        fill(vis.begin(), vis.end(), false);
        int ans = 0;

        while (!order.empty()) {
            int root = order.top();
            order.pop();

            if (vis[root]) continue;

            ans++;

            // Iterative DFS on transposed graph
            stack<int> st;
            st.push(root);
            vis[root] = true;

            while (!st.empty()) {
                int u = st.top();
                st.pop();

                for (int v : adjT[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        st.push(v);
                    }
                }
            }
        }

        return ans;
    }
};
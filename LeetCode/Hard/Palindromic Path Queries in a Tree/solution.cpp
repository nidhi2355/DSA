class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> depth, parent, sz, heavy, head, pos;
    int cur_pos;
    vector<int> bit;
    string cur_s;

    void dfs_sz(int u, int p, int d) {
        parent[u] = p;
        depth[u] = d;
        sz[u] = 1;
        heavy[u] = -1;
        int max_c = 0;
        for (int v : adj[u]) {
            if (v != p) {
                dfs_sz(v, u, d + 1);
                sz[u] += sz[v];
                if (sz[v] > max_c) {
                    max_c = sz[v];
                    heavy[u] = v;
                }
            }
        }
    }

    void dfs_hld(int u, int h) {
        head[u] = h;
        pos[u] = ++cur_pos;
        if (heavy[u] != -1) {
            dfs_hld(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs_hld(v, v);
            }
        }
    }

    void update_bit(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    int query_bit(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum ^= bit[idx];
        }
        return sum;
    }

    int query_range(int l, int r) {
        return query_bit(r) ^ query_bit(l - 1);
    }

    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                swap(u, v);
            }
            res ^= query_range(pos[head[v]], pos[v]);
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        res ^= query_range(pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        this->cur_s = s;
        adj.assign(n, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        depth.assign(n, 0);
        parent.assign(n, 0);
        sz.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        cur_pos = 0;

        dfs_sz(0, 0, 0);
        dfs_hld(0, 0);

        bit.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (cur_s[i] - 'a');
            update_bit(pos[i], mask);
        }

        vector<bool> ans;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                if (cur_s[u] != c) {
                    int old_mask = 1 << (cur_s[u] - 'a');
                    int new_mask = 1 << (c - 'a');
                    update_bit(pos[u], old_mask ^ new_mask);
                    cur_s[u] = c;
                }
            } else {
                int u, v;
                ss >> u >> v;
                int mask = query_path(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};
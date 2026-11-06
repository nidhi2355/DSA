class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<pair<int, int>> indexed_queries(m);
        for (int i = 0; i < m; ++i) {
            indexed_queries[i] = {queries[i], i};
        }
        
        sort(indexed_queries.begin(), indexed_queries.end());
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        vector<int> ans(m);
        vector<int> server_count(n + 1, 0);
        int active_servers = 0;
        int left = 0, right = 0;
        int num_logs = logs.size();
        
        for (int i = 0; i < m; ++i) {
            int q_val = indexed_queries[i].first;
            int q_idx = indexed_queries[i].second;
            int window_start = q_val - x;
            int window_end = q_val;
            
            while (right < num_logs && logs[right][1] <= window_end) {
                int server = logs[right][0];
                if (server_count[server] == 0) {
                    active_servers++;
                }
                server_count[server]++;
                right++;
            }
            
            while (left < num_logs && logs[left][1] < window_start) {
                int server = logs[left][0];
                server_count[server]--;
                if (server_count[server] == 0) {
                    active_servers--;
                }
                left++;
            }
            
            ans[q_idx] = n - active_servers;
        }
        
        return ans;
    }
};
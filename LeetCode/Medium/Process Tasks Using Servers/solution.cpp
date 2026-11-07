class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }

        //{free_time, weight, index}
        priority_queue<tuple<long long, int, int>, 
                       vector<tuple<long long, int, int>>, 
                       greater<tuple<long long, int, int>>> busy_servers;

        vector<int> ans(m);
        long long current_time = 0;

        for (int i = 0; i < m; ++i) {
            current_time = max(current_time, (long long)i);

            if (free_servers.empty()) {
                current_time = max(current_time, get<0>(busy_servers.top()));
            }

            while (!busy_servers.empty() && get<0>(busy_servers.top()) <= current_time) {
                auto [finish_time, weight, idx] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({weight, idx});
            }

            auto [weight, idx] = free_servers.top();
            free_servers.pop();

            ans[i] = idx;
            busy_servers.push({current_time + tasks[i], weight, idx});
        }

        return ans;
    }
};
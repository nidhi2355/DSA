class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> count(k, 0);
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        for (int i = 0; i < n; ++i) {
            long long time = arrival[i];
            long long duration = load[i];

            while (!busy.empty() && busy.top().first <= time) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) {
                continue;
            }

            auto it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;
            count[server]++;
            available.erase(it);
            busy.emplace(time + duration, server);
        }

        int max_requests = *max_element(count.begin(), count.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_requests) {
                result.push_back(i);
            }
        }

        return result;
    }
};
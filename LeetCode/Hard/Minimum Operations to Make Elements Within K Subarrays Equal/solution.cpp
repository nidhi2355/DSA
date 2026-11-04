class Solution {
    struct WindowMedianFinder {
        multiset<long long> left, right;
        long long sum_left = 0, sum_right = 0;
        int k_left;

        WindowMedianFinder(int sz) {
            k_left = (sz + 1) / 2;
        }

        void balance() {
            while (left.size() < k_left && !right.empty()) {
                auto it = right.begin();
                long long val = *it;
                right.erase(it);
                sum_right -= val;
                left.insert(val);
                sum_left += val;
            }
            while (left.size() > k_left) {
                auto it = prev(left.end());
                long long val = *it;
                left.erase(it);
                sum_left -= val;
                right.insert(val);
                sum_right += val;
            }
        }

        void add(long long val) {
            if (left.empty() || val <= *prev(left.end())) {
                left.insert(val);
                sum_left += val;
            } else {
                right.insert(val);
                sum_right += val;
            }
            balance();
        }

        void remove(long long val) {
            auto it = left.find(val);
            if (it != left.end()) {
                left.erase(it);
                sum_left -= val;
            } else {
                it = right.find(val);
                if (it != right.end()) {
                    right.erase(it);
                    sum_right -= val;
                }
            }
            balance();
        }

        long long get_cost() {
            long long median = *prev(left.end());
            return ((long long)left.size() * median - sum_left) + (sum_right - (long long)right.size() * median);
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int total_windows = n - x + 1;
        vector<long long> cost(total_windows);

        WindowMedianFinder wmf(x);
        for (int i = 0; i < x; ++i) {
            wmf.add(nums[i]);
        }
        cost[0] = wmf.get_cost();

        for (int i = x; i < n; ++i) {
            wmf.remove(nums[i - x]);
            wmf.add(nums[i]);
            cost[i - x + 1] = wmf.get_cost();
        }

        const long long INF = 1e18;
        vector<long long> dp(n + 1, 0); 

        for (int j = 1; j <= k; ++j) {
            vector<long long> next_dp(n + 1, INF);
            for (int i = 1; i <= n; ++i) {
                next_dp[i] = next_dp[i - 1];
                if (i >= x && dp[i - x] != INF) {
                    next_dp[i] = min(next_dp[i], dp[i - x] + cost[i - x]);
                }
            }
            dp = move(next_dp);
        }

        return dp[n];
    }
};
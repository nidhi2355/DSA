class Solution {
    static const int MOD = 1e9 + 7;

    struct SegmentTree {
        int n;
        vector<long long> sum;
        vector<long long> sum_sq;
        vector<long long> lazy;

        SegmentTree(int n) : n(n), sum(4 * n, 0), sum_sq(4 * n, 0), lazy(4 * n, 0) {}

        void push(int node, int l, int r) {
            if (lazy[node] == 0) return;
            int mid = l + (r - l) / 2;
            int left_len = mid - l + 1;
            int right_len = r - mid;
            long long val = lazy[node];

            lazy[2 * node] = (lazy[2 * node] + val) % MOD;
            sum_sq[2 * node] = (sum_sq[2 * node] + 2LL * val * sum[2 * node] + val * val % MOD * left_len) % MOD;
            sum[2 * node] = (sum[2 * node] + val * left_len) % MOD;

            lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % MOD;
            sum_sq[2 * node + 1] = (sum_sq[2 * node + 1] + 2LL * val * sum[2 * node + 1] + val * val % MOD * right_len) % MOD;
            sum[2 * node + 1] = (sum[2 * node + 1] + val * right_len) % MOD;

            lazy[node] = 0;
        }

        void update(int node, int l, int r, int ql, int qr, long long val) {
            if (ql <= l && r <= qr) {
                lazy[node] = (lazy[node] + val) % MOD;
                sum_sq[node] = (sum_sq[node] + 2LL * val * sum[node] + val * val % MOD * (r - l + 1)) % MOD;
                sum[node] = (sum[node] + val * (r - l + 1)) % MOD;
                return;
            }
            push(node, l, r);
            int mid = l + (r - l) / 2;
            if (ql <= mid) update(2 * node, l, mid, ql, qr, val);
            if (qr > mid) update(2 * node + 1, mid + 1, r, ql, qr, val);
            sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
            sum_sq[node] = (sum_sq[2 * node] + sum_sq[2 * node + 1]) % MOD;
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree tree(n);
        unordered_map<int, int> last_pos;
        long long total_ans = 0;

        for (int i = 0; i < n; ++i) {
            int prev = last_pos.count(nums[i]) ? last_pos[nums[i]] + 1 : 0;
            tree.update(1, 0, n - 1, prev, i, 1);
            total_ans = (total_ans + tree.sum_sq[1]) % MOD;
            last_pos[nums[i]] = i;
        }

        return total_ans;
    }
};
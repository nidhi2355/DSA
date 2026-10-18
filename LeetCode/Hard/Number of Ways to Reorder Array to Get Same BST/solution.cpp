class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> C;

    void precomputeComb(int n) {
        C.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
    }

    long long dfs(const vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        int root = nums[0];
        vector<int> left, right;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long waysLeft = dfs(left);
        long long waysRight = dfs(right);
        long long comb = C[left.size() + right.size()][left.size()];

        long long total = (comb * waysLeft) % MOD;
        total = (total * waysRight) % MOD;

        return total;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precomputeComb(n);
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
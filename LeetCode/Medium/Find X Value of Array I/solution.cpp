class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        
        for (int x : nums) {
            vector<long long> next_dp(k, 0);
            int val = x % k;
            
            next_dp[val]++;
            
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    next_dp[(r * val) % k] += dp[r];
                }
            }
            
            for (int i = 0; i < k; ++i) {
                ans[i] += next_dp[i];
                dp[i] = next_dp[i];
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.size();
        vector<long long> costs(26, 0);
        long long total = 0;
        
        for (int i = 0; i < n; i++) {
            costs[s[i] - 'a'] += cost[i];
            total += cost[i];
        }
        
        long long ans = LLONG_MAX;
        for (int i = 0; i < 26; i++) {
            if (costs[i] > 0) {
                ans = min(ans, total - costs[i]);
            }
        }
        
        return ans;
    }
};
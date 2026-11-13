class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, ops = 0;
        deque<pair<int, int>> dq;
        
        for (int l = n - 1, r = n - 1; l >= 0; --l) {
            int cnt = 1;
            while (!dq.empty() && dq.front().first <= nums[l]) {
                auto [val, c] = dq.front();
                dq.pop_front();
                ops += 1LL * (nums[l] - val) * c;
                cnt += c;
            }
            dq.push_front({nums[l], cnt});
            
            while (ops > k) {
                auto& [val, c] = dq.back();
                ops -= (val - nums[r]);
                --c;
                if (c == 0) {
                    dq.pop_back();
                }
                --r;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};
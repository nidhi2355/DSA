class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_val = n;
        for (int x : nums) {
            max_val = max(max_val, x);
        }

        vector<int> sa(n), sa2(n), rk(n), tmp(n), cnt(max_val + 1, 0);

        for (int x : nums) cnt[x]++;
        for (int i = 1; i <= max_val; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) sa[--cnt[nums[i]]] = i;

        rk[sa[0]] = 1;
        int classes = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[sa[i]] != nums[sa[i - 1]]) ++classes;
            rk[sa[i]] = classes;
        }

        for (int k = 1; classes < n; k <<= 1) {
            int p = 0;
            for (int i = n - k; i < n; ++i) sa2[p++] = i;
            for (int i = 0; i < n; ++i) {
                if (sa[i] >= k) sa2[p++] = sa[i] - k;
            }

            fill(cnt.begin(), cnt.begin() + classes + 1, 0);
            for (int i = 0; i < n; ++i) cnt[rk[sa2[i]]]++;
            for (int i = 1; i <= classes; ++i) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i) sa[--cnt[rk[sa2[i]]]] = sa2[i];

            tmp[sa[0]] = 1;
            classes = 1;
            for (int i = 1; i < n; ++i) {
                int cur1 = rk[sa[i]], prev1 = rk[sa[i - 1]];
                int cur2 = (sa[i] + k < n) ? rk[sa[i] + k] : 0;
                int prev2 = (sa[i - 1] + k < n) ? rk[sa[i - 1] + k] : 0;
                if (cur1 != prev1 || cur2 != prev2) ++classes;
                tmp[sa[i]] = classes;
            }
            swap(rk, tmp);
        }

        for (int i = 0; i < n; ++i) rk[sa[i]] = i;

        vector<int> lcp(n, 0);
        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (rk[i] > 0) {
                int j = sa[rk[i] - 1];
                while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) {
                    ++h;
                }
                lcp[rk[i]] = h;
                if (h > 0) --h;
            }
        }

        int ans = n;
        for (int idx = 0; idx < n; ++idx) {
            int prev_lcp = lcp[idx];
            int next_lcp = (idx + 1 < n) ? lcp[idx + 1] : 0;
            int req = max(prev_lcp, next_lcp) + 1;
            if (req <= n - sa[idx]) {
                ans = min(ans, req);
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] ^ (1 << (s[i] - 'a'));
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int left = q[0];
            int right = q[1];
            int k = q[2];

            int mask = pref[right + 1] ^ pref[left];
            int odd_count = __builtin_popcount(mask);

            ans.push_back((odd_count / 2) <= k);
        }

        return ans;
    }
};
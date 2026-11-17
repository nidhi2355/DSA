class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> divs(n + 1);
        for (int len = 2; len <= n; len++) {
            for (int d = 1; d * d <= len; d++) {
                if (len % d == 0) {
                    if (d < len) divs[len].push_back(d);
                    if (d != len / d && len / d < len) divs[len].push_back(len / d);
                }
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                for (int d : divs[len]) {
                    int cnt = 0;
                    for (int g = 0; g < d; g++) {
                        int l = i + g;
                        int r = j - (d - 1 - g);
                        while (l < r) {
                            if (s[l] != s[r]) cnt++;
                            l += d;
                            r -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], cnt);
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, 1e9));
        for (int i = 1; i < n; i++) {
            dp[i][1] = cost[0][i];
        }

        for (int p = 2; p <= k; p++) {
            for (int i = 2 * p - 1; i < n; i++) {
                for (int m = 2 * p - 3; m <= i - 2; m++) {
                    dp[i][p] = min(dp[i][p], dp[m][p - 1] + cost[m + 1][i]);
                }
            }
        }

        return dp[n - 1][k];
    }
};
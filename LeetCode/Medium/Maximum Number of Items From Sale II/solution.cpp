class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        long long min_price = LLONG_MAX;

        for (const auto& item : items) {
            freq[item[0]]++;
            min_price = min(min_price, (long long)item[1]);
        }

        vector<int> gain(n + 1, 0);
        for (int f = 1; f <= n; ++f) {
            if (freq[f] == 0) continue;
            int total = 0;
            for (int m = f; m <= n; m += f) {
                total += freq[m];
            }
            gain[f] = total - 1;
        }

        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        long long rem = budget;
        long long ans = 0;

        for (const auto& item : items) {
            long long price = item[1];
            if (price >= 2 * min_price) break;
            long long g = gain[item[0]];
            if (g == 0) continue;

            long long take = min(g, rem / price);
            ans += 2 * take;
            rem -= take * price;

            if (take < g) break;
        }

        ans += rem / min_price;
        return (int)ans;
    }
};
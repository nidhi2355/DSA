class Solution {
    long long power(long long base, long long exp) {
        long long res = 1, mod = 1e9 + 7;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
public:
    int numberOfSets(int n, int k) {
        long long res = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i <= 2 * k; ++i) {
            res = res * (n + k - i) % mod;
            res = res * power(i, mod - 2) % mod;
        }
        return res;
    }
};
class Solution {
    bool isPalindrome(long long x) {
        if (x < 1) return false;
        string s = to_string(x);
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    long long calculateCost(const vector<int>& nums, long long p) {
        long long cost = 0;
        for (int x : nums) {
            cost += abs(x - p);
        }
        return cost;
    }

public:
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long median = nums[n / 2];

        long long p1 = median;
        while (!isPalindrome(p1)) {
            p1--;
        }

        long long p2 = median;
        while (!isPalindrome(p2)) {
            p2++;
        }

        return min(calculateCost(nums, p1), calculateCost(nums, p2));
    }
};
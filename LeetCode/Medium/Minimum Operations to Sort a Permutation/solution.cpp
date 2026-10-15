class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int p = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                p = i;
                break;
            }
        }

        bool inc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(p + i) % n] != i) {
                inc = false;
                break;
            }
        }

        if (inc) {
            if (p == 0) return 0;
            return min(p, n - p + 2);
        }

        bool dec = true;
        for (int i = 0; i < n; i++) {
            if (nums[(p - i + n) % n] != i) {
                dec = false;
                break;
            }
        }

        if (dec) {
            int cost1 = ((p + 1) % n) + 1;
            int cost2 = 1 + (n - 1 - p);
            return min(cost1, cost2);
        }

        return -1;
    }
};
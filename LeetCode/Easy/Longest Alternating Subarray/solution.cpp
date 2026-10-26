class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int expected_diff = ((j - i) % 2 == 1) ? 1 : -1;
                
                if (nums[j] - nums[j - 1] == expected_diff) {
                    maxLen = max(maxLen, j - i + 1);
                } else {
                    break; 
                }
            }
        }

        return maxLen;
    }
};
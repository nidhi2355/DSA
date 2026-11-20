class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> rightMin(n);
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMin[i] = min(nums[i + 1], rightMin[i + 1]);
        }
        
        int totalBeauty = 0;
        int leftMax = nums[0];
        
        for (int i = 1; i <= n - 2; ++i) {
            if (leftMax < nums[i] && nums[i] < rightMin[i]) {
                totalBeauty += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                totalBeauty += 1;
            }
            leftMax = max(leftMax, nums[i]);
        }
        
        return totalBeauty;
    }
};
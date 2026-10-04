class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;
        
        for (int num : nums) {
            // Standard Kadane's for Maximum Subarray Sum
            curMax = max(num, curMax + num);
            maxSum = max(maxSum, curMax);
            
            // Kadane's for Minimum Subarray Sum
            curMin = min(num, curMin + num);
            minSum = min(minSum, curMin);
            
            totalSum += num;
        }
        
        // If all numbers are negative, max sum is the maximum single element
        if (maxSum < 0) {
            return maxSum;
        }
        
        // Return the maximum of non-wrapping or wrapping sum
        return max(maxSum, totalSum - minSum);
    }
};
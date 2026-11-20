class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans=0;

        for(int i=0; i<nums.size(); i++){
            dp[nums[i]+1]= dp[nums[i]]+1;
            dp[nums[i]]= dp[nums[i]-1]+1;

            ans= max({ans, dp[nums[i]], dp[nums[i]+1]});
        }

        return ans;
    }
};
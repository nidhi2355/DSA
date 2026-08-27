class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;

        for(int i=0; i<nums.size(); i++){
            int mine= nums[i], maxe= nums[i];
            for(int j= i+1; j<nums.size(); j++){
                mine= min(mine, nums[j]);
                maxe= max(maxe, nums[j]);
                ans+= 1LL*(maxe-mine);
            }
        }

        return ans;
    }
};
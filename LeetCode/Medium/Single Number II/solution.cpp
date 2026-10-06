class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n= nums.size();
        int i;

        for( i=0; i+2<n; i=i+3){
            if(nums[i]!=nums[i+1]) return nums[i];
        }

        return nums[i];
    }
};
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n= nums.size(), maxlen=1, left=0, right=1;

        while(right<n){
            while(right<n and nums[right]> nums[right-1]) right++;
            maxlen= max(maxlen, right-left);
            left= right;
            right++;
        }

        left=0, right=1;
        while(right<n){
            while(right<n and nums[right]< nums[right-1]) right++;
            maxlen= max(maxlen, right-left);
            left= right;
            right++;
        }

        return maxlen;
    }
};
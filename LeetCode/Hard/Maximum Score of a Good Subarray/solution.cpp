class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n= nums.size();
        int ans= nums[k];
        int i= k, j= k;
        int minval= nums[k];

        while(i>0 or j<n-1){
            int left=-1, right= -1;

            if(i>0) left= nums[i-1];
            if(j<n-1) right= nums[j+1];

            if(left>= right){
                i--;
                minval= min(minval, nums[i]);
            }
            else{
                j++;
                minval= min(minval, nums[j]);
            }

            ans= max(ans, minval*(j-i+1));
        }

        return ans;
    }
};
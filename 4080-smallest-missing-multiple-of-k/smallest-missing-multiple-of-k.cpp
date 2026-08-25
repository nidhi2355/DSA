class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n= nums.size();
        int temp= k;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(nums[i]==temp) temp+= k;
        }

        return temp;
    }
};
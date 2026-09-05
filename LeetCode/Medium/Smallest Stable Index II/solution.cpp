class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n= nums.size();

        vector<int> mins(n);
        vector<int> maxs(n);

        mins[n-1]= nums[n-1];
        maxs[0]= nums[0];

        for(int i=1; i<n; i++){
            maxs[i]= max(maxs[i-1], nums[i]);
        }

        for(int i= n-2; i>=0; i--){
            mins[i]= min(mins[i+1], nums[i]);
        }

        for(int i=0; i<n; i++){
            if(maxs[i]- mins[i] <= k) return i;
        }

        return -1;
    }
};
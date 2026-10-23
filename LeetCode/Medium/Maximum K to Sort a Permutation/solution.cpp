class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n= nums.size();
        bool sorted= true;

        int ans=0;

        for(int i=0; i<n; i++){
            if(nums[i]== i) continue;
            if(sorted){
                ans= nums[i];
                sorted= false;
            }
            else{
                ans&= nums[i];
            }
        }

        return ans;
    }
};
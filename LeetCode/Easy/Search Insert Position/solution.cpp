class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ind=-1;
        int low=0, high= nums.size()-1;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(nums[mid]>=target){
                ind=mid;
                high= mid-1;
            }else{
                low= mid+1;
            }
        }
        if(ind==-1) return nums.size();
        return ind;
    }
};
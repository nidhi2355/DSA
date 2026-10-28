class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op=0, n= nums.size();

        for(int i=2; i<n; i++){
            if(nums[i-2]==0){
                op++;
                nums[i-2]^=1;
                nums[i-1]^= 1;
                nums[i]^=1;
            }
        }

        int sum= accumulate(nums.begin(), nums.end(), 0);
        if(sum == n) return op;
        return -1;
    }
};
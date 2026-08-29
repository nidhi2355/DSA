class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        if(n<=1) return 0;
        int jumps=0, curr=0, maxreach= 0;

        for(int i=0; i<n; i++){
            maxreach= max(i+ nums[i], maxreach);
            if(i==curr){
                jumps++;
                curr= maxreach;
                if(curr>= n-1) break;
            }
        }

        return jumps;
    }
};
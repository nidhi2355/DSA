class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n= nums.size();
        if(n==2) return nums;

        int xorc= 0;

        for(int i=0; i<n; i++){
            xorc^= nums[i];
        }

        int num1=0, num2=0;

        int rightmost_set_bit= 0;
        int cnt=0;
        while(xorc){
            if(xorc&1 == 1){
                rightmost_set_bit= 1<<cnt;
                break;
            }
            cnt++;
            xorc>>=1;
        }

        for(int i=0; i<n; i++){
            if(nums[i] & rightmost_set_bit){
                num1^= nums[i];
            }
            else{
                num2^= nums[i];
            }
        }

        return {num1, num2};
    }
};
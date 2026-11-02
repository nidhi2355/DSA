class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n= nums.size();
        if(n==0 or n==1) return 0;
        sort(nums.begin(), nums.end());
        int minMoves=0;
        int median= nums[n/2];
        for(int i=0;i<n;i++){
            minMoves+= abs(nums[i]-median);
        }
        return minMoves;
    }
};
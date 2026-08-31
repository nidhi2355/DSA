class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans =0;
        int n= nums.size();

        vector<int> leftmax (n);
        vector<int> rightmax(n);

        leftmax[0]= INT_MIN;
        rightmax[n-1]= INT_MIN;

        for(int i=1; i<n; i++){
            leftmax[i]= max(leftmax[i-1], nums[i-1]);
        }

        for(int i=n-2; i>=0; i--){
            rightmax[i]= max(rightmax[i+1], nums[i+1]);
        }

        for(int j=1; j<n-1; j++){
            ans= max(ans, (1LL*(leftmax[j]-nums[j])*(1LL* rightmax[j])));
        }

        return ans;
    }
};
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans= LLONG_MAX;
        long long curr= 0;
        int n= nums.size();

        for(int i=0; i<n; i++){
            curr+= 1LL*nums[i];
        }

        ans= min(ans, curr);

        vector<int> costs= nums;

        for(int k=1; k<= n-1; k++){
            curr=0;

            for(int i=0; i<n; i++){
                costs[i]= min(costs[i], nums[(i+k)%n]);
                curr+= 1LL*costs[i];
            }

            ans= min(ans, 1LL*k*x+ curr);
        }

        return ans;
    }
};
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n= nums.size();
        int cntk=0;

        for(int i=0; i<n; i++){
            if(nums[i]==k) cntk++;
        }

        int maxgain=0;

        for(int v=1; v<=50; v++){
            if(v==k) continue;

            int curr=0, best=0;

            for(int i=0; i<n; i++){
                int val=0;
                if(nums[i]==v) val++;
                else if(nums[i]==k) val--;

                curr= max(0, curr+val);
                best= max(best, curr);
            }

            maxgain= max(maxgain, best);
        }

        return cntk+maxgain;
    }
};
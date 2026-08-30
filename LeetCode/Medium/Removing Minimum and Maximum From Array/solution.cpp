class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n= nums.size();
        if(n<=2) return n;

        int mine=INT_MAX, minind= -1, maxe= INT_MIN, maxind= -1;

        for(int i=0; i<n; i++){
            if(nums[i]< mine){
                mine= nums[i];
                minind= i;
            }
            if(nums[i]> maxe){
                maxe= nums[i];
                maxind= i;
            }
        }

        if(minind> maxind) swap(minind, maxind);

        int op1= maxind+1;
        int op2= n- minind;

        int op3= (minind+1)+ (n-maxind);

        return min({op1, op2, op3});
    }
};
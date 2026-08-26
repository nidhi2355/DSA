class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;

        int prev2= 2, prev1= 3, curr;

        for(int i= 4; i<=n; i++){
            curr= prev1+ prev2;
            prev2= prev1;
            prev1= curr;
        }

        return prev1;
    }
};
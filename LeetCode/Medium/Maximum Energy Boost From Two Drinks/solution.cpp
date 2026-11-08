class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n= energyDrinkA.size();

        vector<vector<long long>> dp(n, vector<long long>(2));

        dp[0][0]= 1LL*energyDrinkA[0], dp[0][1]= 1LL*energyDrinkB[0];

        for(int i=1; i<n; i++){
            long long switchA= 0, switchB=0;

            if(i>1){
                switchA= dp[i-2][1];
                switchB= dp[i-2][0];
            }

            dp[i][0]= max(dp[i-1][0]+ 1LL*energyDrinkA[i],switchA+ 1LL*energyDrinkA[i]);
            dp[i][1]= max(dp[i-1][1], switchB)+ 1LL*energyDrinkB[i];
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};
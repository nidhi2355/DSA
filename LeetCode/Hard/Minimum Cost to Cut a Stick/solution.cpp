class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c= cuts.size();

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

        for(int i= c; i>=1; i--){
            for(int j= i; j<= c; j++){
                dp[i][j]= INT_MAX;
                for(int ind= i; ind<= j; ind++){
                    dp[i][j]= min(dp[i][j], (cuts[j+1]- cuts[i-1]+ dp[i][ind-1]+ dp[ind+1][j]));
                }
            }
        }

        return dp[1][c];
    }
};
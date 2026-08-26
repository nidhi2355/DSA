class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dp(val.size()+1, vector<int> (W+1, 0));
        
        vector<pair<int, int>> combine;
        
        for(int i=0; i<val.size(); i++){
            combine.push_back({wt[i], val[i]});
        }
        
        sort(combine.begin(), combine.end());
        
        int n= combine.size();
        
        for(int i=0; i<n; i++){
            for(int j=1; j<= W; j++){
                int notpick= dp[i][j];
                int pick=0;
                if(j>= combine[i].first){
                    pick= combine[i].second+ dp[i][j-combine[i].first];
                }
                
                dp[i+1][j]= max(pick, notpick);
            }
        }
        
        return dp[n][W];
    }
};
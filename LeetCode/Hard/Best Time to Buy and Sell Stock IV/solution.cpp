class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();

        vector<vector<int>> prev(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        for(int i= n-1; i>=0; i--){
            for(int buy= 0; buy<=1; buy++){
                for(int cap=1; cap<= k; cap++){
                    if(buy==0){
                        curr[buy][cap]= max(prev[buy][cap], -prices[i]+ prev[1][cap]);
                    }
                    else{
                        curr[buy][cap]= max(prev[buy][cap], prices[i]+ prev[0][cap-1]);
                    }
                }
            }

            prev= curr;
        }

        return prev[0][k];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();

        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<= 2; cap++){
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

        return prev[0][2];
    }
};
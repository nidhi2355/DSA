class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, minprice= prices[0];

        for(int i=1; i< prices.size(); i++){
            ans= max(ans, prices[i]- minprice);
            minprice= min(minprice, prices[i]);
        }

        return ans;
    }
};
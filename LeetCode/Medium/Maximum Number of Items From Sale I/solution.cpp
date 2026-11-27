class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n= items.size();
        int minp= INT_MAX;
        for(auto it: items){
            minp= min(minp, it[1]);
        }
        vector<int> gain(n, 0);
        for(int i=0;i<n;i++){
            int cnt=1;
            for(int j=0;j<n;j++){
                if(i!=j and items[j][0]%items[i][0]==0) cnt++;
            }
            gain[i]= cnt;
        }
        vector<int> dp(budget+1, -1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int c= items[i][1];
            int g= gain[i];
            for(int w= budget;w>=c;w--){
                if(dp[w-c]!=-1) dp[w]= max(dp[w], dp[w-c]+g);
            }
        }
        int ans=0;
        for(int w=0;w<=budget;w++){
            if(dp[w]!=-1){
                int curr= dp[w]+ ((budget-w)/minp);
                ans= max(ans, curr);
            }
        }
        return ans;
    }
};
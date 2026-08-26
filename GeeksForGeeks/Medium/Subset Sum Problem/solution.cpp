class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n= arr.size();
        
        sort(arr.begin(), arr.end());
        
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        
        for(int i=0; i<n; i++) dp[i][0]= true;
        
        dp[0][arr[0]]= true;
        
        for(int i=1; i<n; i++){
            for(int j=1; j<= sum; j++){
                bool notpick= dp[i-1][j];
                bool pick= false;
                
                if(j>= arr[i]){
                    pick= dp[i-1][j-arr[i]];
                }
                
                dp[i][j]= pick or notpick;
            }
        }
        
        return dp[n-1][sum];
    }
};
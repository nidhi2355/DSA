class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        int total=0, n= arr.size();
        
        for(int i=0; i<n; i++) total+= arr[i];
        
        if(target> total) return 0;
        
        if((total+ target)%2 != 0) return 0;
        
        target= (total+ target)/2;
        
        vector<int> dp(target+1, 0);
        
        dp[0]= 1;
        
        for(int i=0; i<n; i++){
            for(int j= target; j>= arr[i]; j--){
                dp[j]+= dp[j- arr[i]];
            }
        }
        
        return dp[target];
    }
};
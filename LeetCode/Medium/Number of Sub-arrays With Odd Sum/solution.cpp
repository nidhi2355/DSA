class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddsum=0, evensum=1, ans=0;
        long long curr= 0;
        const int mod= 1e9+7;

        for(int i=0; i<arr.size(); i++){
            curr+= 1LL*arr[i];

            if(curr%2 == 0){
                evensum++;
                ans= (ans+ oddsum)%mod;
            }
            else{
                ans= (ans+ evensum)%mod;
                oddsum++;
            }
        }

        return ans;
    }
};
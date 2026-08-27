class Solution {
public:
    int countHomogenous(string s) {
        const int mod= 1e9+7;

        long long ans=0;

        int n= s.size();

        int right=0, left;
        while(right<n){
            left= right;
            while(right<n and s[right]==s[left]){
                ans= (ans+ right-left+1)%mod;
                right++;
            }
        }

        return ans;
    }
};
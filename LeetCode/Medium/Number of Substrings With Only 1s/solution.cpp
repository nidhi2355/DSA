class Solution {
public:
    int numSub(string s) {
        const int mod = 1e9+7;

        long long ans= 0;
        int n= s.size();

        int right=0;

        while(right<n){
            if(s[right]=='0'){
                right++;
                continue;
            }
            int left= right;

            while(right<n and s[right]=='1'){
                ans= (ans+ (right-left+1))%mod;
                right++;
            }
            right++;
        }

        return (int)ans;
    }
};
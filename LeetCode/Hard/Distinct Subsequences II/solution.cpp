class Solution {
public:
    const int mod= 1e9+7;

    int distinctSubseqII(string s) {
        vector<int> last(26, 0);
        long long ans=1;

        for(char c: s){
            int ch= c-'a';

            long long temp= (2*ans)%mod;

            temp= (temp- last[ch]+mod) % mod;

            last[ch]= ans;

            ans= temp;
        }

        return (ans-1+mod) % mod;
    }
};
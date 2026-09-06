class Solution {
public:
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        if(m>n) return 0;
        vector<long long> prev(m+1,0);
        vector<long long> curr(m+1,0);
        for(int i=n-1;i>=0;i--){
            prev[m]=1;
            for(int j=m-1;j>=0;j--){
                if(s[i]==t[j]){
                    curr[j]= prev[j]+ prev[j+1];
                    if (curr[j] > INT_MAX) curr[j] = INT_MAX;
                }
                else{
                    curr[j]= prev[j];
                }
            }
            prev= curr;
        }
        return (int)prev[0];
    }
};
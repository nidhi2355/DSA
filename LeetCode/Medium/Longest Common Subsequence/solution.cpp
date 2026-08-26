class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size(), m= text2.size();

        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(text1[i]==text2[j]){
                    curr[j+1]= prev[j]+1;
                }
                else{
                    curr[j+1]= max(prev[j+1], curr[j]);
                }
            }
            prev= curr;
        }

        return prev[m];
    }
};
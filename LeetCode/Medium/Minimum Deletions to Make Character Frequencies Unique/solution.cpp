class Solution {
public:
    int minDeletions(string s) {
       vector<int> freq(26, 0);
        int n= s.size();

        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }

        unordered_set<int> st;
        int ans=0;

        for(int i=0; i<26; i++){
            if(freq[i]==0) continue;
            while(freq[i]!=0 and st.find(freq[i])!= st.end()){
                ans++;
                freq[i]--;
            }
            st.insert(freq[i]);
        }

        return ans;
    }
};
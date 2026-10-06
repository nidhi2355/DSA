class Solution {
public:
int ans=1;
unordered_set<string> st;
    int maxUniqueSplit(string s) {
        dfs(0, s);

        return ans;
    }

    void dfs(int ind, string &s){
        if(ind==s.size()){
            int n= st.size();
            ans= max(ans, n);
            return;
        }

        for(int i= ind+1; i<= s.size(); i++){
            if(st.find(s.substr(ind, i-ind)) != st.end()) continue;

            st.insert(s.substr(ind, i-ind));
            dfs(i, s);

            st.erase(s.substr(ind, i- ind));
        }
    }
};
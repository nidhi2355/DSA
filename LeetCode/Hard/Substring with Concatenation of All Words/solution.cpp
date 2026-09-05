class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n= words.size();
        int m= words[0].size();
        int window= n*m;
        if(s.size()<window) return {};
        vector<int> res;

        unordered_map<string, int> mpp;
        for(auto it: words){
            mpp[it]++;
        }

        int i=0;
        while(i<=s.size()-window){
            unordered_map<string, int> temp;
            for(int j=0; j<n; j++){
                string p= s.substr(i+j*m, m);
                temp[p]++;
            }

            if(temp==mpp) res.push_back(i);

            i++;
        }

        return res;

    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for(int i=0; i<strs.size(); i++){
            string temp= strs[i];
            sort(temp.begin(), temp.end());

            mpp[temp].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for(auto &it: mpp){
            res.push_back(it.second);
        }

        return res;
    }
};
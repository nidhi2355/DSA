class Solution {
public:
    string mergeCharacters(string s, int k) {
        string ans;
        vector<int> pos(26, -1e9);
        for (char c : s) {
            int idx = ans.size();
            if (idx - pos[c - 'a'] > k) {
                pos[c - 'a'] = idx;
                ans.push_back(c);
            }
        }
        return ans;
    }
};
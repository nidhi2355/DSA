class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mpp;
        for (int x : deck) mpp[x]++;

        int g = 0;
        for (auto& it : mpp) {
            g = gcd(g, it.second);
        }

        return g >= 2;
    }
};
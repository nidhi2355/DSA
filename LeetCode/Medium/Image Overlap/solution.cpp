class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> p1, p2;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) p1.push_back({i, j});
                if (img2[i][j] == 1) p2.push_back({i, j});
            }
        }
        
        vector<vector<int>> count(2 * n + 1, vector<int>(2 * n + 1, 0));
        int max_overlap = 0;
        
        for (auto& [r1, c1] : p1) {
            for (auto& [r2, c2] : p2) {
                max_overlap = max(max_overlap, ++count[r2 - r1 + n][c2 - c1 + n]);
            }
        }
        
        return max_overlap;
    }
};
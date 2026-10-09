class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int max_points = 0;

        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> slope_count;
            int local_max = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                slope_count[{dx, dy}]++;
                local_max = max(local_max, slope_count[{dx, dy}]);
            }

            max_points = max(max_points, local_max + 1);
        }

        return max_points;
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int end= points[0][1], cnt=1;

        for(int i=1; i<points.size(); i++){
            if(end>= points[i][0]){
                end= min(end, points[i][1]);
            }
            else{
                end= points[i][1];
                cnt++;
            }
        }

        return cnt;
    }
};
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n= points.size();
        int ans=0;

        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){
                if(i==j) continue;
                int x1= abs(points[i][0]- points[j][0]);
                int y1= abs(points[i][1]- points[j][1]);

                for(int k=0; k<n; k++){
                    if(i==k or j==k) continue;
                    int x2= abs(points[i][0]- points[k][0]);
                    int y2= abs(points[i][1]- points[k][1]);

                    if((1LL*x1*x1+ 1LL*y1*y1) == (1LL*x2*x2+ 1LL*y2*y2)) ans++;

                }
            }
        }

        return ans;
    }
};
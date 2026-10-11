class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();
        vector<int> prev(n, 0);
        vector<int> curr(n);
        prev[0]= grid[0][0];
        curr[0]= grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 and j==0) continue;
                else{
                    int up=INT_MAX, left= INT_MAX;
                    if(i>0) up=grid[i][j]+ prev[j];
                    if(j>0) left= grid[i][j]+ curr[j-1];
                    curr[j]= min(up, left);
                }
            }
            prev= curr;
        }
        return prev[n-1];
    }
};
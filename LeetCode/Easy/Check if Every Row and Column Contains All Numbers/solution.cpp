class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n= matrix.size();

        vector<vector<int>> rows(n, vector<int>(n+1, 0));
        vector<vector<int>> cols(n, vector<int>(n+1, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(rows[i][matrix[i][j]] != 0) return false;
                if(cols[j][matrix[i][j]] != 0) return false;

                rows[i][matrix[i][j]]= 1;
                cols[j][matrix[i][j]]= 1;
            }
        }

        return true;
    }
};
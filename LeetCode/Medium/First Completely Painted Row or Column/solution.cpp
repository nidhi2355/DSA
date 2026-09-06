class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m= mat.size(), n= mat[0].size();

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);

        unordered_map<int, pair<int, int>> mpp;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mpp[mat[i][j]]= {i, j};
            }
        }

        for(int i=0; i<arr.size(); i++){
            int row= mpp[arr[i]].first;
            int col= mpp[arr[i]].second;

            rows[row]++;
            cols[col]++;

            if ((rows[row] == n) or (cols[col] == m)) return i;
        }

        return -1;
    }
};
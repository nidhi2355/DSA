class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m= matrix.size(), n= matrix[0].size();

        int srow=0, erow= m-1, scol=0, ecol= n-1, ind=0;

        vector<int> res(m*n);

        while(srow<= erow and scol<= ecol){
            for(int j= scol; j<= ecol; j++){
                res[ind++]= matrix[srow][j];
            }

            srow++;

            for(int i= srow; i<= erow; i++){
                res[ind++]= matrix[i][ecol];
            }

            ecol--;

            if(srow<= erow){
                for(int j= ecol; j>= scol; j--){
                    res[ind++]= matrix[erow][j];
                }
            }

            erow--;

            if(scol<= ecol){
                for(int i= erow; i>= srow; i--){
                    res[ind++]= matrix[i][scol];
                }
            }

            scol++;
        }

        return res;
    }
};
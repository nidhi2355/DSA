class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res(rows*cols);
        int x=1;

        int ind=0;
        res[ind++]= {rStart, cStart};

        while(ind< rows*cols){
            int left= cStart-x;
            int right= cStart+x;
            int top= rStart-x;
            int bottom= rStart+ x;

            if(right>=0 and right< cols){
                for(int i= top+1; i<= bottom; i++){
                    if(i>=0 and i<rows) res[ind++]= {i, right};
                }
            }

            if(ind>=rows*cols) break;

            if(bottom>=0 and bottom < rows){
                for(int j= right-1; j>=left; j--){
                    if(j>=0 and j<cols) res[ind++]= {bottom, j};
                }
            }


            if(ind>=rows*cols) break;

            if(left>=0 and left<cols){
                for(int i= bottom-1; i>= top; i--){
                    if(i>=0 and i<rows) res[ind++]= {i, left};
                }
            }


            if(ind>=rows*cols) break;

            if(top>=0 and top<rows){
                for(int j= left+1; j<= right; j++){
                    if(j>=0 and j<cols) res[ind++]= {top, j};
                }
            }

            x++;
        }

        return res;
    }
};
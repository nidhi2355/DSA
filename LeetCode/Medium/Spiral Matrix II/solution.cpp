class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int ele=1;
        int left=0, right= n-1, top=0, bottom= n-1;

        while(ele<= n*n){
            for(int j= left; j<= right; j++){
                mat[top][j]= ele;
                ele++;
            }

            top++;

            if(ele> n*n) break;

            for(int i= top; i<= bottom; i++){
                mat[i][right]= ele++;
            }

            if(ele> n*n) break;

            right--;

            for(int j= right; j>= left; j--){
                mat[bottom][j]= ele++;
            }

            if(ele> n*n) break;

            bottom--;

            for(int i= bottom; i>= top; i--){
                mat[i][left]= ele++;
            }

            left++;
        }

        return mat;
    }
};
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m= board.size(), n= board[0].size();

        vector<vector<int>> temp(m, vector<int>(n));

        int dx[8]= {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8]= {-1, 0, 1, 1, 1, 0, -1, -1};

        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                int live=0;

                for(int i=0; i<8; i++){
                    int nr= row+ dx[i], nc= col+dy[i];

                    if(nr>=0 and nr<m and nc>=0 and nc<n){
                        if(board[nr][nc]==1) live++;
                    }
                }

                if(board[row][col]==1){
                    if(live<2)temp[row][col]=0;
                    else if(live==2 or live==3) temp[row][col]= 1;
                    else temp[row][col]= 0;
                }
                else{
                    if(live==3) temp[row][col]=1;
                    else temp[row][col]=0;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                board[i][j]= temp[i][j];
            }
        }

        return;
    }
};
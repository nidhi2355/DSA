class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9);
        vector<int> cols(9);
        vector<int> boxes(9);

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;

                int box= 3*(i/3)+ (j/3);

                int d= board[i][j]-'0';
                int bit= 1<<d;

                if(rows[i] & bit) return false;
                if(cols[j] & bit) return false;
                if(boxes[box] & bit) return false;

                rows[i] |= bit;
                cols[j] |= bit;
                boxes[box] |= bit;
            }
        }

        return true;
    }
};
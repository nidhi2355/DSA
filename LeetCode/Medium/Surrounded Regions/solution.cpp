class Solution {
public:
int n, m;
int dx[4]={0, -1, 0, 1};
int dy[4]= {-1, 0, 1, 0};
    void solve(vector<vector<char>>& board) {
        m= board.size(), n= board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(i, 0, board);
            if(board[i][n-1]=='O') dfs(i, n-1, board);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') dfs(0, j, board);
            if(board[m-1][j]=='O') dfs(m-1, j, board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='T') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }

    void dfs(int row, int col, vector<vector<char>> &board){
        board[row][col]='T';
        for(int i=0;i<4;i++){
            int nr= row+ dx[i], nc= col+ dy[i];
            if(nr>=0 and nr<m and nc>=0 and nc<n and board[nr][nc]=='O') dfs(nr, nc, board);
        }
    }
};
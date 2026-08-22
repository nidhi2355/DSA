class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m= board.size(), n= board[0].size();

        queue<pair<int, int>> q;

        for(int i=0; i<m; i++){
            if(board[i][0]=='O') q.push({i, 0});
            if(board[i][n-1]=='O') q.push({i, n-1});
        }

        for(int j=0; j<n; j++){
            if(board[0][j]=='O') q.push({0, j});
            if(board[m-1][j]=='O') q.push({m-1, j});
        }

        int dx[4]={-1, 0, 1, 0};
        int dy[4]= {0, 1, 0, -1};

        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;

            q.pop();

            if(board[row][col]=='#') continue;
            board[row][col]='#';

            for(int i=0; i<4; i++){
                int nr= row+dx[i], nc= col+dy[i];

                if(nr>=0 and nr<m and nc>=0 and nc<n and board[nr][nc]=='O'){
                    q.push({nr, nc});
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
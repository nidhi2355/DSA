class Solution {
public:
    int m, n;

    bool exist(vector<vector<char>>& board, string word) {
        m= board.size(), n= board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(dfs(i, j, board, word, 1, vis)) return true;
                }
            }
        }

        return false;
    }

    bool dfs(int r, int c, vector<vector<char>> &board, string &word, int ind, vector<vector<int>> &vis){
        if(ind == word.size()) return true;

        vis[r][c]=1;

        int dx[4]= {-1, 0, 1, 0};
        int dy[4]= {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nr= r+ dx[i], nc= c+ dy[i];

            if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc] and board[nr][nc]==word[ind]){
                if(dfs(nr, nc, board, word, ind+1, vis)) return true;
            }
        }

        vis[r][c]=0;
        return false;
    }
};
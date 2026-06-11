#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
int n,m;

bool dfs(vector<vector<char>> &mat, vector<vector<int>> &vis, int row, int col, int level){
    vis[row][col]=level;
    for(int i=0;i<4;i++){
        int nr= row+ dx[i];
        int nc= col+ dy[i];
        if(nr>=0 and nr<n and nc>=0 and nc<m and mat[nr][nc]==mat[row][col]){
            if(vis[nr][nc] and (level-vis[nr][nc]+1)>=4) return true;
            else if(!vis[nr][nc]){
                if(dfs(mat, vis, nr, nc, level+1)) return true;
            }
        }
    }
    vis[row][col]=0;
    return false;
}

int main(){
    cin>>n>>m;
    vector<vector<char>> mat(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int> (m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                if(dfs(mat, vis, i, j, 1)) {
                    cout<<"Yes";
                    return 0;
                }
        }
    }
    cout<<"No";
    return false;
}
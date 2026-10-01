class Solution {
public:
    int n;
    vector<int> col;
    vector<int> diag1;
    vector<int> diag2;

    int totalNQueens(int n) {
        this->n= n;
        int ans=0;
        col.assign(n, 0);
        diag1.assign(2*n-1, 0);
        diag2.assign(2*n-1, 0);
        dfs(0, ans);

        return ans;
    }

    void dfs(int r, int &ans){
        if(r== n){
            ans++;
            return;
        }

        for(int c=0; c<n; c++){
            if(!col[c] and !diag1[r+c] and !diag2[c-r+n-1]){
                col[c]=1;
                diag1[r+c]=1;
                diag2[c-r+n-1]=1;

                dfs(r+1, ans);

                col[c]=0;
                diag1[r+c]=0;
                diag2[c-r+n-1]= 0;
            }
        }
    }
};
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;

        for(int i=1; i<=n; i++){
            vector<int> temp;
            temp.push_back(i);
            dfs(i, temp, res, k, n);
            temp.pop_back();
        }

        return res;
    }

    void dfs(int i, vector<int> &temp, vector<vector<int>> &res, int k, int n){
        if(temp.size()==k) {
            res.push_back(temp);
            return;
        }

        if(i>n) return;

        for(int ind= i+1; ind<=n; ind++){
            temp.push_back(ind);
            dfs(ind, temp, res, k, n);
            temp.pop_back();
        }
    }
};
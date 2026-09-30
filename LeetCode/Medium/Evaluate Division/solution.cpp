class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mpp;

        int n= values.size();

        for(int i=0; i<n; i++){
            mpp[equations[i][0]][equations[i][1]]= values[i];
            mpp[equations[i][1]][equations[i][0]]= 1.0/values[i];
        }

        n= queries.size();

        vector<double> res(n, -1.0);

        for(int i=0; i<n; i++){
            if(mpp.find(queries[i][0])== mpp.end() or mpp.find(queries[i][1])== mpp.end()) continue;

            double temp= 1.0;
            unordered_set<string> vis;
            dfs(queries[i][0], queries[i][1], mpp, temp, res, vis, i);
        }

        return res;
    }

    void dfs(string src, string dst, unordered_map<string, unordered_map<string, double>> &mpp, double temp, vector<double> &res, unordered_set<string> &vis, int ind){
        if(vis.find(src) != vis.end()) return;

        vis.insert(src);
        if(src==dst){
            res[ind]= temp;
            return;
        }

        for(auto &it: mpp[src]){
            if (res[ind] != -1.0) return;
            dfs(it.first, dst, mpp, temp*it.second, res, vis, ind);
        }

        return;
    }
};
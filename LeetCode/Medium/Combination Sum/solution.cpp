class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n= candidates.size();
        vector<int> curr;
        vector<vector<int>> res;
        solve(candidates, 0, curr, res, target);
        return res;
    }

    void solve(vector<int> &candidates, int ind, vector<int> &curr, vector<vector<int>> &res, int target){
        if(target==0){
            res.push_back(curr);
            return;
        }

        for(int i=ind; i<candidates.size(); i++){
            if(candidates[i]<= target){
                curr.push_back(candidates[i]);
                solve(candidates, i, curr, res, target-candidates[i]);
                curr.pop_back();
            }
        }
    }
};
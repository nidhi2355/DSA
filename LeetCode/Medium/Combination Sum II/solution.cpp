class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        solve(candidates, 0, curr, ans, target);
        return ans;
    }

private:
    void solve(vector<int> &candidates, int ind, vector<int> &curr, vector<vector<int>> &ans, int target){
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        if(target<0) return;
        for(int i= ind;i<candidates.size();i++){
            if(i>ind and candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            curr.push_back(candidates[i]);
            solve(candidates, i+1, curr, ans, target-candidates[i]);
            curr.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, curr, ans, k, n);
        return ans;
    }

private:
    void solve(int start, vector<int> &curr, vector<vector<int>> &ans, int k, int n){
        if(k==0){
            if(n==0) ans.push_back(curr);
            return;
        }
        if(k<0 or n<0) return;
        for(int i=start;i<=9;i++){
            curr.push_back(i);
            solve(i+1, curr, ans, k-1, n-i);
            curr.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(0, nums, res);
        return res;
    }

    void dfs(int ind, vector<int> &nums, vector<vector<int>> &res){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i=ind; i<nums.size(); i++){
            swap(nums[i], nums[ind]);
            dfs(ind+1, nums, res);
            swap(nums[i], nums[ind]);
        }
    }
};
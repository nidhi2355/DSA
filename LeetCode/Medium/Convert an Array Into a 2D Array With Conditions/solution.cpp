class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n= nums.size();

        unordered_map<int, int> mpp;
        int maxcnt=0;

        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
            maxcnt= max(maxcnt, mpp[nums[i]]);
        }

        vector<vector<int>> res(maxcnt);

        for(auto &it: mpp){
            for(int j=0; j<it.second; j++){
                res[j].push_back(it.first);
            }
        }

        return res;
    }
};
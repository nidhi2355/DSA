class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> st;
        int ans=0;

        for(int i=0; i<nums.size(); i++){
            if(st.count(nums[i])){
                ans^= nums[i];
            }
            st.insert(nums[i]);
        }

        return ans;
    }
};
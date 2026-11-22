class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;

        for(int i=0; i<n; i++){
            string temp= to_string(nums[i]);
            st.insert(nums[i]);
            reverse(temp.begin(), temp.end());
            int num= stoi(temp);
            st.insert(num);
            nums.push_back(num);
        }
        return st.size();
    }
};
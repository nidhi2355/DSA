class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size(), maxlen=0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto it: st){
            if(st.find(it-1)== st.end()){
                int curr= it;
                int len=1;
                while(st.find(curr+1)!= st.end()){
                    curr++;
                    len++;
                }
                maxlen= max(maxlen, len);
            }
        }
        return maxlen;
    }
};
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minEle= *min_element(nums.begin(), nums.end());
        int moves=0;
        for(auto it: nums){
            moves+= (it-minEle);
        }
        return moves;
    }
};
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n= nums.size();

        unordered_set<int> multiples;

        for(int i=0; i<n; i++){
            if(nums[i]%k==0) multiples.insert(nums[i]);
        }

        int temp= k;
        while(multiples.find(temp)!= multiples.end()){
            temp+=k;
        }

        return temp;
    }
};
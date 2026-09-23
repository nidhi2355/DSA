class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total= 0, n= nums.size();

        for(int i=0; i<n; i++) total+= nums[i];

        int req= total- x;

        if(req==0) return n;
        if(req<0) return -1;

        int curr=0, maxlen= INT_MIN;

        unordered_map<int, int> mpp;
        mpp[0]= -1;

        for(int right=0; right<n; right++){
            curr+= nums[right];

            int temp= curr- req;

            if(mpp.find(temp)!= mpp.end()){
                maxlen= max(maxlen, right-mpp[temp]);

            }

            mpp[curr]= right;
        }

        return maxlen==INT_MIN?-1:n-maxlen;
    }
};
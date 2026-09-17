class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n= arr.size();

        unordered_map<int, int> mpp;
        vector<int> bestLen(n, INT_MAX);
        int sum= 0;
        int ans= INT_MAX;
        int minlen= INT_MAX;
        mpp[0]= -1;

        for(int i=0; i<n; i++){
            sum+= arr[i];
            int req= sum- target;

            if(mpp.find(req)!= mpp.end()){
                int start= mpp[req];
                int len= i- start;

                if(start>=0 and bestLen[start]!= INT_MAX){
                    ans= min(ans, len+ bestLen[start]);
                }

                minlen=min(minlen, len);
            }

            mpp[sum]=i;
            bestLen[i]= minlen;
        }

        return ans== INT_MAX?-1:ans;
    }
};
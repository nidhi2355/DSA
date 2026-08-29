class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low= 0, high= *max_element(citations.begin(), citations.end()), ans=0;

        while(low<= high){
            int mid= low+ (high-low)/2;

            int papers= helper(citations, mid);

            if(papers>=mid){
                ans= mid;
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }

        return ans;
    }

    int helper(vector<int> &citations, int value){
        int cnt=0;

        for(int i=0; i<citations.size(); i++){
            if(citations[i]>= value) cnt++;
        }

        return cnt;
    }
};
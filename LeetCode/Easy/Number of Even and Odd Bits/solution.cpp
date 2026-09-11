class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> temp;

        while(n){
            temp.push_back(n%2);
            n/=2;
        }

        vector<int> ans(2);

        for(int i=0; i<temp.size(); i++){
            if(temp[i]==1){
                ans[i%2]++;
            }
        }

        return ans;
    }
};
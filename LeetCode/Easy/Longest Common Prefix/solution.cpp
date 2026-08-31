class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string res= strs[0];

        for(int i=1; i<strs.size(); i++){
            int j=0;
            string temp= "";

            while(j< min(res.size(),strs[i].size())){
                if(res[j]!= strs[i][j]) break;
                temp.push_back(res[j]);
                j++;
            }

            res= temp;
        }

        return res;
    }
};
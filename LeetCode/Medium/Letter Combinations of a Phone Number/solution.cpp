class Solution {
public:
vector<string> ans;
vector<vector<char>> mpp;
int n;
    vector<string> letterCombinations(string digits) {
        n= digits.size();
        mpp.resize(10);

        mpp[2]= {'a', 'b', 'c'};
        mpp[3]= {'d','e','f'};
        mpp[4]= {'g' ,'h', 'i'};
        mpp[5]= {'j', 'k', 'l'};
        mpp[6]= {'m', 'n', 'o'};
        mpp[7]= {'p', 'q', 'r', 's'};
        mpp[8]= {'t', 'u', 'v'};
        mpp[9]= {'w', 'x', 'y', 'z'};

        string curr= "";
        dfs(0, curr, digits);
        return ans;
    }

    void dfs(int ind, string &curr, string &digits){
        if(ind==n){
            ans.push_back(curr);
            return;
        }

        for(auto &it: mpp[digits[ind]-'0']){
            curr+= it;
            dfs(ind+1, curr, digits);
            curr.pop_back();
        }
    }
};
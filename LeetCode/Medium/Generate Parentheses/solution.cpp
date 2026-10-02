class Solution {
public:
vector<string> res;
int n;
    vector<string> generateParenthesis(int n) {
        this->n= n;
        string curr= "";
        dfs(0, 0, curr);
        return res;
    }

    void dfs(int open, int close, string &curr){
        if(open==close and open==n){
            res.push_back(curr);
            return;
        }

        if(open<n){
            curr+='(';
            dfs(open+1, close, curr);
            curr.pop_back();
        }

        if(close<open){
            curr+= ')';
            dfs(open, close+1, curr);
            curr.pop_back();
        }
    }
};
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n= s.size();

        unordered_map<string, string> mpp;

        for(auto & it: knowledge){
            mpp[it[0]]= it[1];
        }

        string res= "";
        int left=0, right=0;

        while(right<n){
            while(right<n and s[right]!= '(') {
                res+= s[right];
                right++;
            }

            if(right<n){
                left= right+1;
                string temp= "";
                right++;

                while(right<n and s[right]!= ')'){
                    temp+= s[right];
                    right++;
                }

                string req="?";
                if(mpp.find(temp)!= mpp.end()){
                    req= mpp[temp];
                }

                res+= req;
            }
            right++;
        }

        return res;
    }
};
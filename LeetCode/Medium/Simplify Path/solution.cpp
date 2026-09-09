class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;

        stringstream ss(path);

        string token;

        while(getline(ss, token, '/')){
            if(token=="") continue;
            if(token==".") continue;
            if(token==".."){
                if(!st.empty()) st.pop_back();
            } 
            else{
                st.push_back(token);
            }
        }

        string res;

        for(auto &it: st){
            res+= '/'+ it;
        }

        return res.empty()? "/":res;
    }
};
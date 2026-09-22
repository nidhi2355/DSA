class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(auto &c: s){
            if(c!='*') st.push(c);
            else{
                st.pop();
            }
        }

        s= "";
        while(!st.empty()){
            s+= st.top();
            st.pop();
        }

        reverse(s.begin(), s.end());
        return s;
    }
};
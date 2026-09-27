class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;

        int n= s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int start= st.top();
                st.pop();

                int l= start+1, r= i-1;

                while(l<r){
                    swap(s[l], s[r]);
                    l++;
                    r--;
                }
            }
        }

        string res= "";
        for(int i=0; i<n; i++){
            if(s[i]!= '(' and s[i]!= ')') res+= s[i];
        }
        return res;
    }
};
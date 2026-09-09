class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string &it: tokens){
            if(it!= "+" and it!="-" and it!="*" and it!="/"){
                st.push(stoi(it));
            }
            else if(it=="+"){
                int y= st.top();
                st.pop();
                int x= st.top();
                st.pop();

                st.push(x+y);
            }
            else if(it=="-"){
                int y= st.top();
                st.pop();
                int x= st.top();
                st.pop();

                st.push(x-y);
            }
            else if(it=="*"){
                int y= st.top();
                st.pop();
                int x= st.top();
                st.pop();

                st.push(x*y);
            }
            else{
                int y= st.top();
                st.pop();
                int x= st.top();
                st.pop();

                st.push(x/y);
            }
        }

        return st.top();
    }
};
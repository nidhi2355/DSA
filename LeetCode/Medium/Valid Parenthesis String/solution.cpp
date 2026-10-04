class Solution {
public:
    bool checkValidString(string s) {
        int n= s.size();
        stack<int> bracket;
        stack<int> star;
        for(int i=0;i<n;i++){
            if(s[i]=='(') bracket.push(i);
            else if(s[i]=='*') star.push(i);
            else{
                if(!bracket.empty()) bracket.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        while(!bracket.empty() and !star.empty()){
            if(bracket.top()>star.top()) return false;
            bracket.pop();
            star.pop();
        }
        return bracket.empty();
    }
};
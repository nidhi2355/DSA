class Solution {
public:
    int maxDepth(string s) {
        int cnt=0, maxcnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt+=1;
                maxcnt= max(cnt,maxcnt);
            }
            else if(s[i]==')') cnt-=1;
        }
        return maxcnt;
    }
};
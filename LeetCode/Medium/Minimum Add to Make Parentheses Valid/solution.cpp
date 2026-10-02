class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0, curr=0, n= s.size();

        for(int i=0; i<n; i++){
            if(s[i]=='(') curr++;
            else{
                if(curr>0) curr--;
                else{
                    cnt++;
                }
            }
        }

        return cnt+curr;
    }
};
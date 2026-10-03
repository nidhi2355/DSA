class Solution {
public:
    int minInsertions(string s) {
        int n= s.size();

        int open=0, close=0, cnt=0;

        for(int i=0; i<n; i++){
            if(s[i]=='(') open++;
            else{
                if(i<n-1 and s[i+1]==')'){
                    close++;

                    if(open< close) {
                        cnt++;
                        open++;
                    }
                    i++;
                }

                else{
                    cnt++;
                    close++;

                    if(open < close){
                        cnt++;
                        open++;
                    }
                }
            }
        }

        if(open> close){
            cnt+= 2*(open-close);
        }

        return cnt;
    }
};
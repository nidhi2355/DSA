class Solution {
public:
    bool sumGame(string num) {
        int cntleft=0, cntright=0, sumleft=0, sumright=0;
        int n= num.size();

        for(int i=0; i<n/2; i++){
            if(num[i]=='?') cntleft++;
            else sumleft+= (num[i]-'0');
        }

        for(int i= n/2; i<n; i++){
            if(num[i]=='?'){
                cntright++;
            }
            else{
                sumright+= (num[i]-'0');
            }
        }

        if((cntleft+cntright)%2!=0) return true;

        if(9*(cntleft-cntright)==2*(sumright-sumleft)) return false;
        return true;
    }
};
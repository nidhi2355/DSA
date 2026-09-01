class Solution {
public:
    string convert(string s, int numRows) {
        int n= s.size();
        if(numRows==1) return s;

        vector<string> temp(numRows);
        int i=0, ind= 0;

        bool flag= true;

        while(ind< n){
            if(flag== true){
                temp[i]+= s[ind];
                i++;
                if(i==numRows){
                    flag= false;
                    i= numRows-2;
                }
            }
            else{
                temp[i]+= s[ind];
                i--;
                if(i==-1){
                    i= 1;
                    flag= true;
                }
            }
            ind++;
        }

        s= "";

        for(auto &it: temp) s+= it;

        return s;
    }
};
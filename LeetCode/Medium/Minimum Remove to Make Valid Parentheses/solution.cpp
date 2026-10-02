class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n= s.size();
        int cnt=0;
        string res="";
        vector<int> open;
        vector<int> pos(n);

        for(int i=0; i<n; i++){
            if(s[i]!= '(' and s[i]!= ')'){
                pos[i]=1;
                continue;
            }

            if(s[i]=='(') {
                cnt++;
                open.push_back(i);
            }
            else{
                cnt--;
            }

            if(cnt>=0) pos[i]=1;
            else {
                pos[i]=0;
                cnt++;
            }
        }

        while(cnt>0){
            int p= open.back();
            open.pop_back();
            pos[p]=0;
            cnt--;
        }

        for(int i=0; i<n; i++){
            if(pos[i]) res+= s[i];
        }

        return res;
    }
};
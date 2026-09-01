class Solution {
public:
    string reverseWords(string s) {
        vector<string> rev;

        int n= s.size();
        int i=0;

        while(i<n){
            while(i<n and s[i]==' ') i++;

            if(i>=n) break;

            int right= 1;
            while(i+right < n and s[i+right]!= ' ') right++;

            rev.push_back(s.substr(i, right));

            i += right;
        }

        s= "";
        for(int i=rev.size()-1; i>=0; i--) s+= rev[i]+' ';
        s.pop_back();

        return s;
    }
};
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n= s.size();

        queue<int> q;
        int start= -1, minlen= INT_MAX;

        for(int i=0; i<n; i++){
            if((s[i]-'0')== 1){
                q.push(i);
            }

            if(q.size()== k){
                if(i-q.front()+1 < minlen){
                    minlen= i-q.front()+1;
                    start= q.front();
                }
                else if(i-q.front()+1 == minlen){
                    if(s.substr(start, minlen) > s.substr(q.front(), minlen)){
                        start= q.front();
                    }
                }
                q.pop();
            }
        }

        if(start==-1) return "";
        return s.substr(start, minlen);
    }
};
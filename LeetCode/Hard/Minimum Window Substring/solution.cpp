class Solution {
public:
    string minWindow(string s, string t) {
        string res= "";
        int n= s.size(), m= t.size();
        if(m>n) return res;

        vector<int> freq(128, 0);

        for(int i=0; i<m; i++){
            freq[t[i]]++;
        }

        int cnt= m;

        int left=0, minlen= INT_MAX, start=0;
        for(int right=0; right<n; right++){
            if(freq[s[right]]> 0) cnt--;

            freq[s[right]]--;

            while(cnt==0){
                if(right-left+1 < minlen){
                    minlen= right-left+1;
                    start= left;
                }

                freq[s[left]]++;
                if(freq[s[left]]> 0) cnt++;

                left++;
            }
        }
        return minlen==INT_MAX? "": s.substr(start, minlen);
    }
};
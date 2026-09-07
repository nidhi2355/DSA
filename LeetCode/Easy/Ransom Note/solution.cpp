class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        int cnt=0;

        for(char &c: ransomNote){
            freq[c-'a']++;
            cnt++;
        }

        for(char &c: magazine){
            if(freq[c-'a']>0){
                freq[c-'a']--;
                cnt--;
            }

            if(cnt==0) return true;
        }

        return cnt==0;
    }
};
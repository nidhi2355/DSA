class Solution {
public:
    bool checkString(string s) {
        vector<bool> freq(2, false);
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' and freq[1]==true) return false;
            freq[s[i]-'a']= true; 
        }
        return true;
    }
};
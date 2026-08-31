class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string temp;

        string res= "";

        while(ss>>temp) res= temp;

        return res.size();
    }
};
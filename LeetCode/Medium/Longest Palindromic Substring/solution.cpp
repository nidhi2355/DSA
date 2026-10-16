class Solution {
public:
int start=0;
int maxlen=0;
    string longestPalindrome(string s) {
        int n= s.size();

        for(int i=0; i< n; i++){
            checkPalindrome(s, i, i);
            checkPalindrome(s, i, i+1);
        }

        return s.substr(start, maxlen);
    }

    void checkPalindrome(string &s, int left, int right){
        int n= s.size();
        while(left>=0 and right<n){
            if(s[left]!= s[right]) return;

            int len= right-left+1;
            if(len>maxlen){
                maxlen= len;
                start= left;
            }
            left--;
            right++;
        }
    }
};
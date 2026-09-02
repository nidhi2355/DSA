class Solution {
public:
    bool isPalindrome(string s) {
        string temp= "";

        for(int i=0; i<s.size(); i++){
            if(isalphanum(s[i])){
                temp+= tolower(s[i]);
            }
        }

        int i=0, j= temp.size()-1;

        while(i<j){
            if(temp[i]!= temp[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    bool isalphanum(char &c){
        if((c>=65 and c<= 90) or (c>= 97 and c<= 122) or (c>= '0' and c<= '9')) return true;
        return false;
    }
};
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans=0;

        for(int i= left; i<= right;i++){
            string temp= words[i];
            if(isvowel(temp[0]) and isvowel(temp.back())) ans++;
        }

        return ans;
    }

    bool isvowel(char &c){
        return c=='a'|| c=='e' || c=='i' || c=='o' || c=='u';
    }
};
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;

        for(int i=0; i<words.size(); i++){
            if(find(words[i], x)) res.push_back(i);
        }

        return res;
    }

    bool find(string &s, char c){
        for(auto &it: s){
            if(it==c) return true;
        }

        return false;
    }
};
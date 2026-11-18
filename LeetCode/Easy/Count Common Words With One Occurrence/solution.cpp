class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> temp;
        unordered_set<string> st1;
        unordered_set<string> st2;

        for(auto &it: words1) temp[it]++;

        for(auto &it: temp){
            if(it.second == 1) st1.insert(it.first);
        }

        temp.clear();

        for(auto &it: words2) temp[it]++;

        for(auto &it: temp){
            if(it.second == 1) st2.insert(it.first);
        }

        int ans=0;

        for(auto &it: st1){
            if(st2.find(it)!= st2.end()) ans++;
        }

        return ans;
    }
};